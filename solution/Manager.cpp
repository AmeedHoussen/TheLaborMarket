#include "Manager.h"

#include <vector>

namespace mtm{
    bool sortemploes(mtm::Employee* e1 , mtm::Employee* e2)
    {
        if(e1->getId()<e2->getId())
        { return true;}
        else{return false;}

    }
    Manager::Manager( int id1, std::string firstName1, std::string lastName1,  int birthYear1)
            : Citizen(id1, std::move(firstName1), std::move(lastName1), birthYear1),salary(0) {}

     int Manager::getSalary() const {
        return this->salary;
    }
    void Manager::setWorkSpaceName( const std::string name){
        this->workSpaceName=name;
    }
    std::string Manager::getWorkSpaceName( ) const{
        return  this->workSpaceName;
    }
    void Manager::addEmployee(Employee *employee) {
        for(auto it = employeesGroup.begin();it != employeesGroup.end();it++)
        {
            if((*it)->getId() == (employee)->getId()){
                throw EmployeeAlreadyHired();
            }
        }

        employeesGroup.push_back(employee);
        this->employeesGroup.sort(sortemploes);
    }

    void Manager::removeEmployee(int employeeId) {
        for(auto it = employeesGroup.begin();it != employeesGroup.end();it++)
        {
            if((*it)->getId() == employeeId){
                employeesGroup.erase(it);
                return;
            }
        }
        throw EmployeeIsNotHired();
    }

    void Manager::setSalary(int increase) {
        if(this->getSalary()+increase<=0){
            this->salary=0;
        } else{
            this->salary=this->getSalary()+increase;
        }


    }

    std::ostream &Manager::printShort(std::ostream & os) const {
        os << this->getFirstName() << " " << this->getLastName() << std::endl
           << "Salary: " << this->getSalary() << std::endl;
        return os;
    }


    std::ostream &Manager::printLong(std::ostream & os) const{
        os << this->getFirstName() << " " << this->getLastName() << std::endl
           << "id - " << this->getId() << " birth_year - " << this->getBirthYear() <<  std::endl
           << "Salary: " << this->getSalary() << std::endl;
           //<< "Employees: " << std::endl;
        if(!employeesGroup.empty())os<< "Employees: " << std::endl;
        //else os<<std::endl;
        for (const auto &item : this->employeesGroup)
        {
            item->printShort(os);
        }
        //for(const auto& emp: this->employeesGroup)
           // emp.printShort(os);
        //os  << std::endl;
        return os;
    }

    Manager *Manager::clone() const {
        return new Manager(*this);
    }

}
