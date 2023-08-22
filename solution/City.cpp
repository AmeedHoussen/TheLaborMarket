
#include "City.h"
#include <algorithm>


namespace mtm {



    City::City(const std::string &name) : name(name) {}

    void City::addEmployee( int id1, std::string firstName1, std::string lastName1,  int birthYear1) {
        bool isHere=false;
        for (const auto &item : this->employees)
        {
            if (item->getId()==id1)
            {
                isHere= true;
                break;
            }
        }
        if(isHere)
        {
             throw CitizenAlreadyExists();
            return;
        }
        for (const auto &item : this->managers)
        {
            if (item->getId()==id1)
            {
                throw CitizenAlreadyExists();
                return;
            }
        }
        Employee* employee = new Employee(id1,firstName1,lastName1,birthYear1);
        this->employees.insert(employee);
    }

    void City::addManager( int id1, std::string firstName1, std::string lastName1,  int birthYear1) {
        for (const auto &item : this->managers)
        {
            if (item->getId()==id1)
            {
                throw CitizenAlreadyExists();
                return;
            }
        }
        bool isHere=false;
        for (const auto &item : this->employees)
        {
            if (item->getId()==id1)
            {
                isHere= true;
                break;
            }
        }
        if(isHere)
        {
            throw CitizenAlreadyExists();
            return;
        }
        Manager* manager = new Manager(id1,firstName1,lastName1,birthYear1);
        this->managers.insert(manager);
    }


    void City::createWorkplace( int id, const std::string &name,int workersSalary, int managersSalary) {
        for (const auto &item : this->workplaces)
        {
            if(item->getId()==id)
            throw WorkplaceAlreadyExists();
        }
        Workplace* workplace = new Workplace(id,name,workersSalary,managersSalary);
        this->workplaces.insert(workplace);
    }

    void City::teachAtFaculty( int employeeId,  int facultyId) {
        bool checkFaculty = true, checkEmployee = true ;
        for (auto fac: faculties) {
            if (fac.getId() == facultyId) {
                for (Employee* emp: employees) {
                    if (emp->getId() == employeeId) {
                        fac.teach(emp);
                        return;
                    }
                }
                checkFaculty = false;
            }
        }
        if (checkFaculty) throw FacultyDoesNotExist();
        if (checkEmployee) throw EmployeeDoesNotExist();
    }

    void City::hireManagerAtWorkplace( int idManager,  int idWorkplace) {
        bool isManager = false, isWorkplace = false;
        for (Workplace* wp: this->workplaces) {
            if (wp->getId() == idWorkplace) {
                isWorkplace = true;
                for (Manager* mg: managers) {
                    if (idManager == mg->getId()) {
                        wp->hireManager(mg);
                        isManager = true;
                    }
                }
            }
        }
        if (!isWorkplace)throw WorkplaceDoesNotExist();
        if (!isManager)throw ManagerDoesNotExist();

    }

    void City::fireEmployeeAtWorkplace( int idEmployee,  int idManager,  int idWorkplace) {
        bool checkWorkPlace= true,checkManager= true,checkEmployee= true;
        for (Workplace* wp: workplaces) {
            if (wp->getId() == idWorkplace) {
                checkWorkPlace = false;
                for (Manager *mg: managers) {
                    if (idManager == mg->getId()) {
                        checkManager = false;
                        for (Employee *emp: employees) {
                            if (idEmployee == emp->getId()) {
                                checkEmployee = false;
                                mg->removeEmployee(emp->getId());
                                emp->setSalary(-wp->getWorkersSalary());
                                break;
                            }
                        }
                    }
                }
            }
        }
        if (checkWorkPlace)throw WorkplaceDoesNotExist();
        if (checkManager)throw ManagerDoesNotExist();
        if (checkEmployee)throw EmployeeDoesNotExist();
    }

    void City::fireManagerAtWorkplace( int idManager,  int idWorkplace) {
        bool checkWorkPlace= true,checkManager= true;
        for (Workplace* wp: workplaces) {
            if (wp->getId() == idWorkplace) {
                checkWorkPlace = false;
                for (Manager *mg: managers) {
                    if (idManager == mg->getId()) {
                        checkManager = false;
                        wp->fireManager(idManager);
                        mg->employeesGroup.clear();
                    }
                }
            }
        }

        if (checkWorkPlace)throw WorkplaceDoesNotExist();
        if (checkManager)throw ManagerDoesNotExist();
    }

    int City::getAllAboveSalary(std::ostream &os, int salary) const {
        std::vector< int> SetId;
        std::vector<double> salaries;

        for (Employee *emp: employees) {
            if (emp->getSalary() >= salary) {
                salaries.push_back(emp->getSalary());
                SetId.push_back(emp->getId());

            }
        }
        for (Manager *mg: managers) {
            if (mg->getSalary() >= salary) {
                salaries.push_back(mg->getSalary());
                SetId.push_back(mg->getId());
            }
        }
        std::sort(SetId.begin(),SetId.end());
        for ( int itr: SetId) {
            for (Employee* e: employees) {
                if (e->getId() == itr) {
                    e->printShort(os);
                    break;
                }

            }

            for (Manager* mg: managers) {
                if (mg->getId() == itr) {
                    mg->printShort(os);
                    break;
                }
            }

        }
        return salaries.size();
    }

    bool City::isWorkingInTheSameWorkplace( int idEmployee1,  int idEmployee2) const {
        bool CheckId1=false,CheckId2= false;
        for (const auto &item : this->employees)
        {
            if(item->getId()==idEmployee1)
            {
                CheckId1= true;
            }
        }
        for (const auto &item : this->employees)
        {
            if(item->getId()==idEmployee2)
            {
                CheckId2= true;
            }
        }
        if(!CheckId1 || !CheckId2)
        {
            throw EmployeeDoesNotExist();
        }

         CheckId1=false,CheckId2= false;
        for (Workplace* workplace: workplaces) {
            for (Manager *mg: workplace->getManagers()) {
                for (Employee *e : mg->employeesGroup) {
                    if (e->getId() == idEmployee1) {
                        for (Employee *e1: mg->employeesGroup) {
                            if(e1->getId()==idEmployee2)return true;
                            else CheckId2=true;
                        }

                    }
                    else CheckId1= true;
                }
            }
        }
    return false;

    }
    void City::printAllEmployeesWithSkill(std::ostream &os, int skill) const{
        for ( Employee* item : this->employees)
        {
            if (item->hasSkill(skill))
            {
                item->printShort(os);
            }
        }
    }

    City::~City() {
        for (const auto &item : this->employees)
        {
            delete item;
        }
        for (const auto &item : this->managers)
        {
            item->employeesGroup.clear();
            delete item;
        }
        for (const auto &item : this->workplaces){
            item->managers.clear();
            delete item;
        }

    }
}