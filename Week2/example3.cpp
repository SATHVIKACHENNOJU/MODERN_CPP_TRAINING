#include<iostream>
#include<functional>
/*

std::functions<T> is a wrapper that can be used to represent a callable
of a certain signatre T

Since this entire data type declaration is lengthy,we can create
an alias for it with "using" Keyword

[](int32_t number){return number%2==0;}

I want to put it in a wrapper
So type T (signature):bool(int32_t)

so wrapper is:std::function<bool(int32_t)>

now create an alias called "predicate"

using predicate=std::function<bool(int32_t)>;

*/
using Predicate = std::function<bool(int32_t)>;

void Adaptor(Predicate fn,int32_t* arr,unsigned int size){
    /*for every index "i" in the range of size arr,
    call fn by passing arr[i](ith position value in the array)*/

    for(int32_t i=0;i<size;i++){
      if(  fn(arr[i])){
        std::cout<<arr[i]<<"\t";
        
      }
    }
}

int main(){
    //auto fn=[](int32_t number){return number*number;};
    auto fn2=[](int32_t number1){return number1%2==0;};
    int32_t arr[3]={11,18,21};
   // Adaptor(fn,arr,3);
    Adaptor(fn2,arr,3);

}