/*Types of logics(functions) we can write in cpp:(How many callables are there)
Global functions
Member functions
Lambda functions

*/

/*
std::function wrapper

*wrapper can store functions

Header file for functional programming -> #include<functional>

*/

#include<functional>
#include<vector>
#include<iostream>
using Logic = std::function<void (int32_t)>;
using DataContainer = std::vector<int32_t>;

void Adaptor(Logic fn,DataContainer& data){
    for(int32_t val:data)
    {
        fn(val);
    }
}

/*[](int32_t number){

    std::cout<<number*number*number<<"\n";
}*/

int main(){
    DataContainer data{1,2,3};

    auto fn=[](int32_t number){
        std::cout<<number*number*number<<"\n";
    };
    Adaptor(fn,data);
    Adaptor(
    [](int32_t number){std::cout<<number*100<<"\n";},
    data
    );
    Adaptor([](int32_t number){std::cout<<number*0.1f<<"\n";},data);
}


