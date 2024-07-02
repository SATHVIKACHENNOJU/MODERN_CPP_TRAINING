#include<iostream>
#include<functional>

int main(){
    auto fn=[](int32_t number,int32_t factor){return number/factor;};

    //while binding lambda functions,don't use & symbol for function name
    auto partially_implemented_fn=std::bind(fn,100,std::placeholders::_1);
   std::cout<< partially_implemented_fn(20)<<std::endl;
    std::cout<<partially_implemented_fn(20,1,2,3,4,5,6,7)<<std::endl;//fn(100,20);//all other inputs are discarded
    auto demo=std::bind(fn,std::placeholders::_2,std::placeholders::_1);
    std::cout<<demo(100,20)<<std::endl;
    /*unlike functions bind accepts extra parameters and simply discard them instead of giving error*/

    
}