#ifndef WORKPLACE_H
#define WORKPLACE_H

#include <set>
#include <iostream>
#include <string>
#include <vector>
#include "Manager.h"
#include "exceptions.h"

namespace mtm {

    class Workplace {
    private:
        int id;
        std::string name;
       int workersSalary;
       int managersSalary;
        std::set<Manager*> managers;

    public:
        //friendship with the city to enable private components accessing
        friend class City;
        //workplace constructing method that allocates new workplace with basic informations
        //workplace id, name , employees salaries and managers salaries
        Workplace( int id, const std::string &name, int workersSalary, int managersSalary);

        //workplace equality comparison operator between different workplaces
        friend bool operator==(const Workplace &w1, const Workplace &w2);
        //workplace smaller than comparison operator
        friend bool operator<(const Workplace &w1, const Workplace &w2);

        //method that returns workplaces private id
        int getId() const;
        //method that returns workplace private name
        const std::string &getName() const;
        //method that returns workplace's employees given salaries
        int getWorkersSalary() const;
        //method that returns workplace's managers given salaries
        int getManagersSalary() const;

        //function that adds a set of managers to specific workplace
        const std::set<Manager*>& getManagers()const;


        //employement template in workplace that hires employee in workplace under manager
        //if didnt exist
        template<class T>
        void hireEmployee(T & condition, Employee  *employeePtr, int managerId){

            bool checkId= false;
            auto i=managers.begin();
            for(;i!=managers.end();i++){
                if((*i)->getId()==managerId){
                    checkId= true;
                    break;
                }
            }

            if(condition(employeePtr) && checkId){

                const_cast<Manager*&>(*i)->addEmployee( employeePtr);
                employeePtr->setSalary(this->getWorkersSalary());
                return;
            }
            if(!condition(employeePtr)){
                throw EmployeeNotSelected();
            }
            if(checkId == false){
                throw ManagerIsNotHired();
            }
        }

        //function that hires new manager in workplace
        void hireManager(Manager *managerPtr);
        //function that fires employee under known manager in workplace
        void fireEmployee( int idEmployee, int idManager);
        //function that fires manager from workplace
        void fireManager( int idManager);

        //output operator definition in workplace for description displaying
        friend std::ostream &operator<<(std::ostream &os, const Workplace &workplace) ;
    };
}

#endif
