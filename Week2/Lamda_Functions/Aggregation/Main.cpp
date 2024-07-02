#include "Functionalities.h"

int main() {
    EmployeeContainer employees;
    ProjectContainer projects;
    CreateObjects(employees, projects);
    auto fn=[](Employee* employees )
            {
                return employees->project().get().budget() > 7000;
                };
    FilterEmployees(fn,employees);
    Deallocate(employees, projects);
}