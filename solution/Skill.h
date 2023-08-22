#ifndef Skill_H
#define Skill_H


#include <iostream>
#include <string>
#include "exceptions.h"



namespace mtm{

    class Skill{

    private:
         int id;
        std::string skillName;
         int requiredPoints;


    public:
        //object constructor that allocates skill with its basic values
        //required points to get, name and id
        Skill(int id,std::string skillName, int requiredPoints) ;
        //object destructor for deallocates existing object
        virtual ~Skill() = default;

        //object equality comparison operator
        friend bool operator==(const Skill &skill1, const Skill &skill2);
        //object smaller than comparison operator
        friend bool operator<(const Skill &skill1, const Skill &skill2);

        //increment operator of the object
        Skill& operator+=(int points);

        //method that returns the private skill's id
        int getId() const;
        //method that returns the private skill's name
        const std::string &getName() const ;
        //method that returns the private skill's required points to get
        int getRequiredPoints() const;

        //output operator for skills printing
        friend std::ostream &operator<<(std::ostream &os, const Skill &skill);

        //increment operator of 1 requirement point
        Skill operator++(int);

    };
    //increament operator of skill and positive points number
    Skill operator+(const Skill& skill,int points);
    //increament operator of positive points number and skill
    Skill operator+(int points,const Skill& skill);

    //object smaller or equal to comparison operator
    bool operator<=(const Skill &skill1, const Skill &skill2) ;
    //object greater than comparison operator
    bool operator>(const Skill &skill1, const Skill &skill2) ;
    //object greater or equal to comparison operator
    bool operator>=(const Skill &skill1, const Skill &skill2) ;
    //object different from or unequal comparison operator
    bool operator!=(const Skill &skill1, const Skill &skill2);

}


#endif //Skill_H
