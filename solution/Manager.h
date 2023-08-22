#ifndef MANAGER_H
#define MANAGER_H

#include "Citizen.h"
#include "Employee.h"
#include <list>
#include "algorithm"

namespace mtm {

    class Manager : public mtm::Citizen {
    private:
        std::string workSpaceName;
       int salary;
        std::list<Employee*> employeesGroup;

    public:
        //creating a friendship between manager and his workplace to share some of its private components
        friend class Workplace;
        //creating a friendship between manager and his city to share some of its private components
        friend class City;

        ///object constructor that allocates new manager citizen with its basic values
        //and sets his salary to zero
        //first name, last name, id and birth year
        Manager( int id1, std::string firstName1, std::string lastName1,  int birthYear1);

        //method that returns managers private salary value
        int getSalary() const;
        //function for icreasing/decreasing an employees salary
        void setSalary(int salary) ;

        //functions that adds a new employee to a manager existing employees group if didnt exist
        void addEmployee(Employee *employee);
        //functions that removes an existing employee from a manager employees group if existed
        void removeEmployee(int employeeId);

        //mehtod that prints short manager description
        std::ostream &printShort(std::ostream & os)const ;
        //method that prints full manager description with his employees group description
        std::ostream &printLong(std::ostream & os) const;

        //function that sets manager workplace name
        void setWorkSpaceName( const std::string name);
        //method that returns manager private workplace name
        std::string getWorkSpaceName( ) const;

        //cloning existing manager citizen and returning pointer to it
        Manager *clone() const override;


    };
}

#endif //MANAGER_H
