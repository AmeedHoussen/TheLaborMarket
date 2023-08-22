#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
#include <stdexcept>

namespace mtm{
    class Exception: public std::exception{} ;
    class NegativePoints : public Exception{};
    class SkillAlreadyLearned : public Exception{};
    class CanNotLearnSkill : public Exception{};
    class DidNotLearnSkill : public Exception{};
    class EmployeeAlreadyHired : public Exception{};
    class EmployeeNotHired : public Exception{};
    class  EmployeeIsNotHired : public Exception{};
    class ManagerIsNotHired : public Exception{};
    class EmployeeNotSkilled : public Exception{};
    class EmployeeNotAccepted : public Exception{};
    class EmployeeNotSelected : public Exception{};

    class EmployeeDoesNotExist : public Exception{};
    class ManagerDoesNotExist : public Exception{};
    class WorkplaceDoesNotExist : public Exception{};
    class CitizenAlreadyExists : public Exception{};
    class  WorkplaceAlreadyExists : public Exception{};

    class ManagerAlreadyHired : public Exception{};
    class CanNotHireManager : public Exception{};
    class FacultyAlreadyExists : public Exception{};

    class EmployeeAlreadyExists : public Exception{};
    class ManagerAlreadyExists : public Exception{};
    class WorkPlaceAlreadyExists : public Exception{};
    class EmployeeDoesNoteExists : public Exception{};
    class FacultyDoesNotExist : public Exception{};
    class WorkPlaceDoesNotExist : public Exception{};
    class ManagerDoesNotExists : public Exception{};


}
#endif //EXCEPTIONS_H
