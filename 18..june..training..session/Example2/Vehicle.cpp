#include<iostream>

class Vehicle
{
private:
    std::string m_id{""};
    std::string m_modelname{""};
public:
    Vehicle()=delete;
    ~Vehicle()=default;
    /*
    Vehice constructor that takes one const lvalue reference
    to a vehicle as a parameter
    */
   Vehicle(const Vehicle& other)=default;//copy constructor
   Vehicle(std::string id,std::string name) : m_id{id},m_modelname{name}{}
};

int main(){
    Vehicle v1{"101","DEzire"};
    //this will not work if copy con is set to delete
    Vehicle v2(v1);//v2{"101","DEzire"}

    //one more possible way to copy data is
    int n1=10;
    int n2=20;
    //copy n1 to n2 after n2 was already initialize earlier
    n2=n1;

    Vehicle v3=v1;//construction using copy constructor only
    Vehicle v4{v1};//in modern cpp there is no any significance for = we can simply use {} instead of it
    Vehicle v5{};//default constructor is deleted so getting error

    v5=v1;
}