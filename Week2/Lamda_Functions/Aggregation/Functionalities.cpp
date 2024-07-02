#include "Functionalities.h"

void CreateObjects(EmployeeContainer &employees, ProjectContainer &projects)
{
    projects.emplace_back(new Project("c.111", 10, 1000.0f));

    projects.emplace_back(new Project("c.221", 50, 11000.0f));
    projects.emplace_back(new Project("c.331", 20, 10000.0f));

    auto itr = projects.begin(); // itr is pointing to the begining of the list
    employees.emplace_back(new Employee(101, "Harshit", **itr++));
    employees.emplace_back(new Employee(101, "Rohan", **itr++));
    employees.emplace_back(new Employee(101, "Riya", **itr++));
}

void Deallocate(EmployeeContainer employees, ProjectContainer projects)
{
    // for(unsigned int i = 0; i < size; i++ ) {
    //     delete projects[i];
    //     delete employees[i];
    // }

    for (Employee *emp : employees)
    {
        delete emp;
    }

    for(Project *pr : projects){
        delete pr;
    }
}
void FilterEmployees( Predicate fn,EmployeeContainer &employees)
{
    for (Employee *emp : employees)
    {
        if (fn(emp))
        {
            std::cout << *emp << "\n";
        }
    }
}

void DisplayProjectBudget(const EmployeeContainer &employees)
{
    for (const Employee *emp : employees)
    {
        std::cout << emp->project().get().budget() << "\n";
    }
}