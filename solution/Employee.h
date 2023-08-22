#ifndef EMPLOYEE_H
#define EMPLOYEE_H



#include <vector>
#include <string>
#include "Skill.h"
#include "Citizen.h"
#include "exceptions.h"


namespace mtm{
    //employed citizen object
    class Employee : public Citizen {
    private:
        int salary;
         int score;
        std::vector<Skill> skills;

    public:
        //object constructor that allocates new employeed citizen with its basic values
        //and sets his salary and score to zero
        //first name, last name, id and birth year
        Employee( int id, std::string firstName, std::string lastName,  int birthYear);
        //object destructor of an employee that deallocates its values
        ~Employee() = default;
        //object copy constructor method allocate based on existing object and sets it to default
        Employee(const Employee &employee) =default;

        //method that returns private employee's salary
        int getSalary() const;
        //method that returns private employee's score
        int getScore() const;

        //method that increase/decrease an existing employee's salary
        void setSalary(int increase);
        //method that increase/decrease an existing employee's salary
        void setScore(int points);

        //function that checks if an existing employee has a specific skill
        bool hasSkill( int skillId);
        //function that removes specific skill from employees set
        void forgetSkill( int skillId);

        //short printing method for basic employee's description
        std::ostream &printShort(std::ostream & os) const override ;
        //long printing method for full employee's description with specified skills
        std::ostream &printLong(std::ostream & os) const override ;

        //function that teachs an exisiting employee aspecific skill
        void learnSkill(const Skill &skill) ;
        //cloning an employee based on an existing citizen
        Employee *clone()  const override;

        //equality comparison operator of 2 employees
        friend bool operator==(const Employee &e1,const Employee &e2){
            return e1.getId() == e2.getId();
        }

    };
}



#endif //EMPLOYEE_H
