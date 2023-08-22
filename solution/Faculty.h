#ifndef UNTITLED3_FACULTY_H
#define UNTITLED3_FACULTY_H
#include <set>
#include <iostream>
#include <string>
#include <vector>
#include "Skill.h"
#include "Employee.h"


namespace mtm{
    class Condition{
    public:
        //condition operator of employement accepting
        virtual bool operator()(Employee* employee) = 0;
    };
    // faculty template of condition
    template<class T>
    class Faculty{
        int id;
         int points;
        T* condition;
        Skill skill;
    public:
        //object constructor which allocates new faculty with its parameters
        //faculty id, skill that it teachs, points that it gives, accepting condition
        Faculty( int id,Skill skill, int points  ,T* condition):id(id),points(points),
        condition(condition),skill(skill){};

        //method that returns the faculty private id
        int getId()const;
        //method that returns the number of points the faculty ads
        int getAddedPoints()const;
        //method that returns the skill that the faculty teachs
        Skill getSkill()const;

        //function that gets employee and teach him a specific skill
        void teach(Employee *employee);
    };



    //faculty template method for retuning id
    template <class T>
     int Faculty<T>::getId() const{
        return this->id;
    }

    //faculty template method for returning skill points the faculty taught
    template <class T>
     int Faculty<T>::getAddedPoints() const {
        return this->points;
    }

    //faculty template method that returns the specific skill the faculty teachs
    template <class T>
    Skill Faculty<T>::getSkill()const {
        return this->skill;
    }

    //faculty teaching template for employees
    template <class T>
    void Faculty<T>::teach(Employee *employee){
        if(condition->operator()(employee)){
            employee->learnSkill(skill);
            employee->setScore(points);
        }
        else{
            throw EmployeeNotAccepted();
        }
    }
}
#endif //UNTITLED3_FACULTY_H
