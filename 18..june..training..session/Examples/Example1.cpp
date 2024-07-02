/*

Employee
    -int id,string name,string designation,categorical Department,float salary



*/
#include<iostream>
#include"Department.h"


class Employee
{
    private:
        unsigned int m_id{0};//default value for m_id
        std::string m_name{""};//default value for m_name
        std::string m_designation{"Executive"};
        Department m_dept{Department::IT};
        float m_salary{0.0f};
    public:
        Employee()=default;//enable the default constructor
        ~Employee()=default;//destructor is enabled
        Employee(const Employee& other)=delete;//disable copy constructor

        /*by 22 line we enabled the copy but at 24 as employee is own data type i can make any rules so i am blocking the copy*/

        Employee& operator=(const Employee& other)=delete;
        Employee(Employee&& other)=delete;//move constructor
        Employee& operator=(Employee&& other)=delete;
        //listing feature-no nosense of this keyword-member list initialization
        Employee(unsigned int id,std::string name,std::string des,Department dept,float salary) : m_id{id},m_name{name},m_salary{salary},m_designation{des},m_dept{dept}{

        }

};

int main(){
   // Employee* e1=new Employee();

  //normally Employee* ptr=NULL;//Declartion of a pointer ptr

  //in mcpp it is replaced with nullptr;

  Employee* ptr=nullptr;
  ptr=new Employee();
  ptr=new Employee(101,"Sathvika","Trainee",Department::IT,9000.0f);//parameterised Constructor
  Employee* tpr{nullptr};//uniform initialization

  int n1{10};
  int* ptr{nullptr};
  int arr[3]{1,2,3};
  Employee e1{};//default constructor
  Employee e2{102,"surya","Admin",Department::ADMIN,8000.0f};
  //std::list<int> data{1,2,3,4,5};
}

