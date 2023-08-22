#include <iostream>
#include "Workplace.h"

namespace mtm {


    Workplace::Workplace( int id, const std::string &name, int workersSalary, int managersSalary)
            : id(id), name(name),
              workersSalary(workersSalary), managersSalary(managersSalary) {}

     int Workplace::getId() const {
        return this->id;
    }
    bool operator==(const Workplace &w1, const Workplace &w2){
        return (w1.id == w2.id);
    }
    bool operator<(const Workplace &w1, const Workplace &w2){
        return (w1.id < w2.id);
    }
    const std::set<Manager *> & Workplace::getManagers() const {
        return this->managers;
    }
    const std::string &Workplace::getName() const {
        return this->name;
    }

    int Workplace::getWorkersSalary() const {
        return this->workersSalary;
    }

   int Workplace::getManagersSalary() const {
        return this->managersSalary;
    }
    std::ostream &operator<<(std::ostream &os, const Workplace &workplace) {
        os << "Workplace name - " << workplace.name ;
        if (!workplace.managers.empty())
        {os<<" Groups:" <<std::endl;}
        else{
            os<<"\n";
            return os;
        }

        for(std::set<Manager*>::iterator it=workplace.managers.begin();it!=workplace.managers.end();it++ ){
            os<< "Manager " ;
            (*it)->printLong(os);
        }
        return os;
    }
    void  Workplace::hireManager(Manager *managerPtr){
        for(auto it=this->managers.begin(); it!=this->managers.end();it++){
            if(managerPtr->getId()== it.operator*()->getId()){
                throw ManagerAlreadyHired();
            }
        }
        if(managerPtr->getSalary()>0){
            throw CanNotHireManager();
        }
        for ( auto &item : managerPtr->employeesGroup)
        {
         item->setSalary(this->getWorkersSalary());
        }
        managerPtr->setSalary(getManagersSalary());
        managers.insert(managerPtr);

    }
    void Workplace::fireEmployee( int idEmployee, int idManager){
        bool checkManger= false;
        std::set<Manager*>::iterator it;
        for( it=managers.begin();it!=managers.end();it++){
            if((*it)->getId()==idManager){
                checkManger= true;
                const_cast<Manager*&>(*it)->removeEmployee(idEmployee);
                break;
            }

        }
        if(!checkManger){
            throw ManagerIsNotHired();
        }
    }
    void Workplace::fireManager( int idManager) {
        std::set<Manager*>::iterator it;
        for (it = managers.begin(); it != managers.end(); it++) {
            if ((*it)->getId() == idManager) {
                const_cast<Manager*&>(*it)->setWorkSpaceName("");
                it.operator*()->setSalary(-this->getManagersSalary());
                for ( auto &item : it.operator*()->employeesGroup)
                {
                    item->setSalary(-this->getWorkersSalary());
                }
                managers.erase(it);
                return;
            }
        }
            throw ManagerIsNotHired();

    }


}