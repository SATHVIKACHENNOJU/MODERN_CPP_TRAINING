#include"Employee.h"

#include"BusinessOwner.h"

#include<variant>

using VrType=std::variant<BusinessOwner,Employee>;

void Display(const VrType& v){
    // if(std::get<0>(v)){

    // }


    // try{
    //     BusinessOwner b=std::get<0>(v);
    //     std::cout<<b<<"\n";
    // }


    std::visit(  [](auto &&val){std::cout<<val<<"\n";} ,   v   );


}

int main(){
    std::variant<BusinessOwner,Employee> vr;

    Employee e1{"Sathvika",10000.0f};

    BusinessOwner b1{"Surya",11000.0f};

    vr=e1;

    Display(vr);

    vr=b1;//changed vr to take BusinessOwner

    Display(vr);
}