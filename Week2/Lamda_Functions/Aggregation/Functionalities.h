#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "Employee.h"
#include "Project.h"
#include<list>
#include<functional>

//using ProjectRef=std::reference_wrapper<Project>;
using EmployeeContainer=std::list<Employee*>;
using ProjectContainer=std::list<Project*>;
using Predicate=std::function<bool(Employee*)>;
void CreateObjects(EmployeeContainer &employees, ProjectContainer &projects);
void FilterEmployees(Predicate fn,EmployeeContainer &employees);
void DisplayProjectBudget(const EmployeeContainer &employees);
void Deallocate(EmployeeContainer employees, ProjectContainer projects);

#endif // FUNCTIONALITIES_H
