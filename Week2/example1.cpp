//week 2: MODERN CPP Starts
/*
software to be built:
-------->diagnostics of a car at workshop!
Dianostics process is different for cars based on model and current status
ex:differnt process car met with accident,malfunctioning electronics,seating problems,tier problems.....so many scenarios....

Functional Programming:
used for handling large amounts of data or to pass logics as inputs(passig function as a parameter
to another function,returning function from the function)
*/

/*
Objective:I want to write an "Adaptor" function

which will accept
a)vector of integer 32 bit numbers
b)a function that accepts a single integer 32 values and returns void

Adaptor should "map" function provided onto the data provided.
//basicallu making a library kind of tool for people with programming knowkedge not for normal people
*/

/*
Function Pointer:
->address of a function
Data type:void (ptr1*)Square(int32_t number) =&Square;
          void (ptr2*)Cube(int32_t number)=&Cube;
}
*/
#include<iostream>
#include<vector>

void Square(int32_t number){
    std::cout<<number*number<<"\n";
}

void Cube(int32_t number){
    std::cout<<number*number*number<<"\n";
}

void Adaptor(void (*fn)(int32_t number),std::vector<int32_t>& data){

//for each number in data,run the function with the number
for(int32_t val:data)
{
    (*fn)(val);
}
}

int main(){
   /* void (ptr1*)Square(int32_t number) =&Square;
    void (ptr2*)Cube(int32_t number)=&Cube;

    (*ptr2)(10);//calls cube function as Cube(10);
    (ptr)(9);//square function as square(9);*/
    std::vector<int32_t> data{1,2,3,4,5};
    Adaptor(&Cube,data);
    Adaptor(&Square,data);
    //if user wants they can design their own function and use its logic to process data
}