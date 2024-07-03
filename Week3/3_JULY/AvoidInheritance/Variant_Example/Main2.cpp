/*
    1)Keep the data on the heap
    2)use the varint for "functional Polymorphisam"
    3)

*/
/*
    A function which accepts another function as a parameter  or returns a function is called "Higher-Order" function
*/
#include<iostream>
#include<variant>
#include"Employee.h"
#include"BusinessOwner.h"

//MISRA-C (important c guidelines to be followed)

using VrType=std::variant<BusinessOwner*,Employee*>;


void ShowPfAmount(  const VrType& val   ){

    bool flag{false};

    if(std::holds_alternative<Employee*>(val)){
        Employee* e=std::get<1>(val);
        flag=true;
        e->CalculateMonthlyPf();
    }
    if(!flag)
    throw std::runtime_error("Not Valid For BusinessOwner type data");

}
//common behavior can be executed using visit
void ShowTaxAmount( const VrType& val   ){
    std::visit( [](auto&& val){val->calculateTaxAmount();});
}
void Display(const VrType& v){

    std::visit( [](auto &&val){std::cout<<*val<<"\n";} , v );

}



int main(){
    VrType v;

    v=new BusinessOwner{"Sathvika",100000.0f};

    Display(v);

    v=new BusinessOwner{"Srinidhi",120000.0f};

    Display(v);
}