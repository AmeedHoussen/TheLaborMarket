
#include "Citizen.h"
#include <string>


namespace mtm {

    Citizen::Citizen( int id,std::string firstName,std::string lastName, int birthYear) : id(id)
            ,firstName(std::move(firstName)),lastName(std::move(lastName)),birthYear(birthYear) {}

     int Citizen::getId() const {
        return this->id;
    }

    const std::string &Citizen::getFirstName() const {
        return this->firstName;
    }


    const std::string &Citizen::getLastName() const {
        return this->lastName;
    }

    int Citizen::getBirthYear() const {
        return this->birthYear;
    }
    bool operator==(const Citizen &Citizen1, const Citizen &Citizen2){
        return (Citizen1.getId() == Citizen2.getId());
    }
    bool operator<(const Citizen &Citizen1, const Citizen &Citizen2){
        return ((Citizen1.getId()<Citizen2.getId()));
    }

    Citizen *Citizen::clone() const {
        return new Citizen(*this);
    }

    bool operator<=(const Citizen &Citizen1,const Citizen &Citizen2){
        return ((Citizen1<Citizen2)||(Citizen1==Citizen2));
    }
    bool operator>(const Citizen &Citizen1, const Citizen &Citizen2){
        return !(Citizen1<=Citizen2);
    }
    bool operator>=(const Citizen &Citizen1,const Citizen &Citizen2) {
        return !((Citizen1<Citizen2));
    }
    bool operator!=(const Citizen &Citizen1,const Citizen &Citizen2){
        return !(Citizen1==Citizen2) ;
    }




}
