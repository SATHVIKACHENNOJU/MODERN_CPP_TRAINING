#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include "Project.h"
#include<functional>

using ProjectRef = std::reference_wrapper<Project>;

class Employee
{
private:
    int _id{0};
    std::string _name{""};
    ProjectRef _project;
public:
    Employee(int id, std::string name, ProjectRef pr);
    ~Employee();
    Employee()= default;

    ProjectRef project() const { return _project; }
    void setProject(const ProjectRef project) { _project = project; }

    friend std::ostream &operator<<(std::ostream &os, const Employee &rhs) {
        os << "_id: " << rhs._id
           << " _name: " << rhs._name
           << " _project: " << rhs._project;
        return os;
    }

   

    
};

#endif // EMPLOYEE_H

/*
    Project&

    lvalue Reference to a Project
*/
