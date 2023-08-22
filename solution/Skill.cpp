
#include "Skill.h"

#include <iostream>
#include <string>




namespace mtm {

    Skill::Skill(int id,std::string skillName, int requiredPoints) {
        this->id = id;
        this->skillName = std::move(skillName);
        this->requiredPoints = requiredPoints;
    }



    bool operator==(const Skill &skill1, const Skill &skill2){
        return (skill1.getId() == skill2.getId());
    }

    bool operator<(const Skill &skill1, const Skill &skill2){
        return ((skill1.getId()<skill2.getId()));
    }


     int Skill::getId() const {
        return this->id;
    }

    const std::string &Skill::getName() const {
        return this->skillName;
    }

     int Skill::getRequiredPoints() const {
        return this->requiredPoints;
    }


    std::ostream &operator<<(std::ostream &os, const Skill &skill) {
        os << skill.getName() << std::endl;
        return os;
    }


    Skill operator+(const Skill& skill,int points){
        if(points<0)
            throw NegativePoints();
        Skill temp(skill.getId(),skill.getName(),skill.getRequiredPoints());
        temp+=points;

        return temp;
    }
    Skill operator+(int points,const Skill& skill){
        if(points<0)
            throw NegativePoints();
        Skill temp(skill);
        temp+=points;

        return temp;
    }


    bool operator<=(const Skill &skill1, const Skill &skill2){
        return ((skill1<skill2)||(skill1==skill2));
    }

    bool operator>(const Skill &skill1, const Skill &skill2){
        return !(skill1<=skill2);
    }

    bool operator>=(const Skill &skill1, const Skill &skill2) {
        return !(skill1<skill2);
    }

    bool operator!=(const Skill &skill1, const Skill &skill2){
        return !(skill1==skill2) ;
    }


    Skill &Skill::operator+=(int points) {

        if(points<0)
            throw NegativePoints();
        this->requiredPoints=this->getRequiredPoints()+points;
        return (*this);

    }

    Skill Skill::operator++(int) {
        Skill temp = *this;
        *this+=1;
        return temp;
    }
}


