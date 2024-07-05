#include<iostream>
#include<memory>
int main(){
    int32_t x{10};
    char grade{'A'};
//     int* ptr1=(int*)malloc(4);
//     char* ptr2=(char*)malloc(1);


//the scope of this unique pointer is inside this main so when we reach main it gets deleted pointer getting deleted means heap memory deallocated automatically
    std::unique_ptr<int>ptr1{(int*)malloc(4)};//using c syntax
    std::unique_ptr<int>ptr2{new int()};//using cpp syntax
    std::unique_ptr<char>ptr3{(char*)malloc(4)};

    if(true){
        std::cout<<*ptr1<<"\n";
    }
    else{
        throw;//;
    }


 }

/*
Stack Main Function

0x108H  ptr1    0x242117H
0x104H  grade   A
0x100H  x       10

***stack and heap will always be in the opposite directions***
*/

/*
HEAP Memory allocation in cpp

    void CalculateResult(inpu value){
        
        //allocate something on heap
        ptr=heap memory address

        if(Value == condition){
        do something with ptr
        //delete ptr;->imagine can't immedietly delete

        if(condition1){
        take action}
        }
        else if(condition 2){
        throw exception
        }
        else if(condition 3){
        throw exception;
        }
        else{
        do something
        }

//complexity is growing and writing  deallocating in every scope is head ace and may lead to errors which get worse
        else{
        delete ptr;
        throw exception
        }
    }



*/
/*

    SMART POINTER(can be implementes using memory header which introduced in cpp11)

    ->we can make smart pointer even for class also
    
    We have 3 type of Smart Pointers:
        1)unique pointer(a template class)
        2)shared pointer
        3)





*/