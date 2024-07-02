/*
    first class functions

    A language is said to treat "functions" as first-class if the following 
    things are possible in the language

    a)functions have a properly recognizable types
    b)functions can be pases as parameters to the functions
    c)functions can be returned as parameters from the functions(closures)
    d)functions can be addressed/copied into other variables
    e)functions can be stored in containers



*/

#include<iostream>
#include<vector>
#include<functional>

void Magic(std::function<void(const int32_t)> fn){
    fn(10);//square of 10
}
//rule 3 part 1

std::function<void(int32_t)>Demo(){
    return 
}
int main(){
    //Type of fn
    /*
    A function which accepts on int32_t by value,return void
    */

   auto fn=[](const int32_t val){std::cout<<val*val<<"\n";};

   //rule 2
   Magic(fn);//works

   //rule 3 part 2

   auto ans=Demo();//accept the function returned in a variable

   //rule4

   auto temp=ans;//'function' copied

   auto* ptr=&ans;//addressing also works

   //rule5:function can be saved in other containers

   std::vector< std::function<void(int32_t)> >fns {fn};

}