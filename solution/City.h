#ifndef UNTITLED3_CITY_H
#define UNTITLED3_CITY_H
#include <set>
#include <string>
#include <iostream>
#include "Citizen.h"
#include "Manager.h"
#include "exceptions.h"
#include "Employee.h"
#include "Faculty.h"
#include <vector>
#include "Workplace.h"

namespace mtm{
    struct sort{
        bool operator () (Citizen* c1 ,Citizen* c2 )
        {
            if (c1->getId()<c2->getId())
            {
                return true;
            }
            return false;
        }
    };
    class City{
    private:


        std::vector<Faculty<Condition>>faculties;
        std::set<Workplace*>workplaces;
        std::string  name;
        std::set<Employee*,sort>employees;
        std::set<Manager*,sort>managers;



    public:
        //city constructing function based on its name
        City(const std::string &name) ;

        //function that adds new employee to the city based on employement requirements
        void addEmployee( int id1, std::string firstName1, std::string lastName1,  int birthYear1);
        //function that adds new manager to the city based on employement requirements for managers
        void addManager( int id1, std::string firstName1, std::string lastName1, int birthYear1);

        //template for creating faculty in the city based on faulty condition and specifications
        //if didnt exist
        template<class T>
        void addFaculty( int id,Skill skill, int points  ,T* condition){

            for (const auto &item : this->faculties)
            {
                if(item.getId()==id)
                {
                    throw FacultyAlreadyExists();
                }
            }

            Faculty<Condition> f1 = Faculty<Condition>(id,skill,points,condition);
            this->faculties.push_back(f1);

        }
        //function that adds new workplace to the city based on the requirements to create one
        void createWorkplace( int id, const std::string &name, int workersSalary, int managersSalary);
        //function that sends employee to a faculty to learn at
        void teachAtFaculty( int employeeId,int facultyId);

        //funtion template to hire an employee at workplace under a given manager
        //if none existed
        template<class T>
        void hireEmployeeAtWorkplace(T condition, int idEmployee, int idManager, int idWorkplace){
            bool checkWorkPlace= false,checkManager= false,checkEmployee= false;
            for (const auto &item : this->employees)
            {
                if (item->getId()==idEmployee)
                {
                    checkEmployee= true;
                    break;
                }
            }
            if(!checkEmployee)
            {
                throw EmployeeDoesNotExist();
                return;
            }
            for(Workplace* wp:workplaces){
                if(idWorkplace==wp->getId()){
                    checkWorkPlace= true;
                    for(Manager* mg:managers){
                        if(idManager==mg->getId()){
                            checkManager= true;
                            for(Employee* emp:employees){
                                if(emp->getId()==idEmployee){
                                    checkEmployee= true;
                                    if(condition(emp)){
                                        mg->addEmployee(emp);
                                        emp->setSalary(wp->getWorkersSalary());
                                        return;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            if(!checkWorkPlace)throw WorkplaceDoesNotExist();
            if(!checkManager)throw ManagerDoesNotExist();
        }
        //funtion that hires a manager at given workplace and sets its salary
        void hireManagerAtWorkplace( int idManager,int idWorkplace);
        //function that fires employee under specific manager from workplace in the city
        //if he existed
        void fireEmployeeAtWorkplace( int idEmployee, int idManager, int idWorkplace);
        //function to fire a manager from given workplace
        void fireManagerAtWorkplace( int idManager,int idWorkplace);
        //function that prints all the salaries paid at workplace
        int getAllAboveSalary(std::ostream &os, int salary) const;
        //funtion that checks if 2 given employees work at the same place by their id numbers
        bool isWorkingInTheSameWorkplace( int idEmployee1, int idEmployee2) const;
        //function that prints employees that share the same skill
        void printAllEmployeesWithSkill(std::ostream &os, int skill) const;

        //city destructor that deallocates existing city
        virtual ~City();
    };

}
#endif //UNTITLED3_CITY_H
