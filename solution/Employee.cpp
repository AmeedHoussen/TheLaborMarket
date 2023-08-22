#include <utility>
#include <vector>
#include "Skill.h"
#include "Employee.h"
#include <string>
using std::endl;
namespace mtm{
    Employee::Employee( int id, std::string firstName, std::string lastName,  int birthYear) : Citizen(
            id, std::move(firstName), std::move(lastName), birthYear),salary(0),score(0) {
        this->salary=0;
        this->score=0;
        this->skills={};

    }

     int Employee::getScore() const {
        return this->score;
    }

    int Employee::getSalary() const {
        return this->salary;
    }

    void Employee::setSalary(int increase){
        if(this->getSalary()+increase<0)
        {
            this->salary=0;
            return;
        }
        this->salary=this->getSalary()+increase;

    }

    void Employee::setScore(int points){
        if(this->getScore()+points<0)
        {
           this->score=0;
            return;
        }
        this->score=this->getScore()+points;

    }


    bool Employee::hasSkill(int skillId) {
        std::vector<Skill>::iterator it;
        it=skills.begin();
        for(unsigned int i=0;i <skills.size();i++){
            if(it->getId()==skillId)
                return true;
            ++it;
        }
        return false;
    }

    void Employee::forgetSkill( int skillId){
        if(!(this->hasSkill(skillId))){
            throw  DidNotLearnSkill();
        }
        std::vector<Skill>::iterator it;
        it=skills.begin();
        for(unsigned int i=0;i <skills.size();i++){
            if(it->getId()==skillId){
                setScore(this->score-it->getRequiredPoints());
                skills.erase(it);
                break;
            }
            ++it;
        }
    }

    std::ostream &Employee::printShort(std::ostream & os) const {
        os << this->getFirstName() << " " << this->getLastName() << endl
           << "Salary: " << this->getSalary() << " Score: " << this->getScore() << endl;
        return os;
    }

    std::ostream &Employee::printLong(std::ostream & os) const {
        std::vector<Skill>SortSkills;
        SortSkills=skills;
        os << this->getFirstName() << " " << this->getLastName() << endl
           << "id - " << this->getId() << " birth_year - " << this->getBirthYear() <<  endl
           << "Salary: " << this->getSalary() << " Score: " << this->getScore()  ;
        if(!skills.empty())os<<" Skills: "<<endl;
        else os<<endl;
       for( auto  i=skills.cbegin();i !=skills.cend();++i)
            os << *i;

        return os;
    }

    void Employee::learnSkill(const Skill &skill) {
        std::vector<Skill>::iterator it;
        if(this->score <skill.getRequiredPoints()){
            throw CanNotLearnSkill();
        }
        if(hasSkill(skill.getId())){
            throw SkillAlreadyLearned();
        }

        for(it=skills.begin();it!=skills.end();it++){
            if( (it)->getId() > skill.getId()){
                skills.insert((it),skill);
                return;
            }
        }
        //setScore(skill.getRequiredPoints()+this->getScore());

        skills.push_back(skill);
//            skills.insert(skills.end()+1,skill);

    }

    Employee * Employee::clone() const{
        return new Employee(*this);
    }


}
