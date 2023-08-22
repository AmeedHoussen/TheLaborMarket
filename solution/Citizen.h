#ifndef Citizen_H
#define Citizen_H
#include <iostream>
#include <string>

namespace mtm{
    //citizen object
    class Citizen{
    private:
         int id;
        std::string firstName;
        std::string lastName;
         int birthYear;

    public:
        //object constructor that allocates new citizen with its basic values
        // first name, last name, id and birth year
        Citizen( int id,std::string firstName,std::string lastName, int birthYear) ;
        //object copy constructor method allocate based on existing object
        Citizen(const Citizen& c1){
            id=c1.getId();
            firstName=c1.getFirstName();
            lastName=c1.getLastName();
            birthYear=c1.getBirthYear();
        }

        //object equality comparison operator
        friend bool operator==(const Citizen &Citizen1, const Citizen &Citizen2);
        //object equality comparison operator
        friend bool operator<(const Citizen &Citizen1, const Citizen &Citizen2);

        //short printing method for basic object description
        virtual std::ostream &printShort(std::ostream &os) const{return os;};
        //long printing method for full object description
        virtual std::ostream &printLong(std::ostream &os) const{return os;};
        //object cloning of citizen returning pointer to it
        virtual Citizen * clone() const;

        //method that returns the private citizen's id
        int getId() const;
        //method that returns the private citizen's first name
        const std::string &getFirstName() const ;
        //method that returns the private citizen's last name
        const std::string &getLastName() const;
        //method that returns the private citizen's birth year
        int getBirthYear() const;
        //object destructor function that deallocate existing citizen
        virtual ~Citizen() = default;



    };




    //object smaller or equal to comparison operator
    bool operator<=(const Citizen &Citizen1,const Citizen &Citizen2) ;
    //object greater than comparison operator
    bool operator>(const Citizen &Citizen1,const Citizen &Citizen2) ;
    //object greater or equal to comparison operator
    bool operator>=(const Citizen &Citizen1,const Citizen &Citizen2) ;
    //object different from or unequal comparison operator
    bool operator!=(const Citizen &Citizen1,const Citizen &Citizen2);

}
#endif //CITIZEN_H
