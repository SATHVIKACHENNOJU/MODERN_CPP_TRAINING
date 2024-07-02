/*

    Terminilogies:
        1)CPU: Set of hardware responsible for executing tasks in a operating system.

        2)SYSTEM:Any computing device.

        3)Processor : Hardware chip(made of silicion)designed for executing instructions given by user of the computer

        e.g:intel 17-1265U

        4)socket:point on the motherboard where processor connected

        5)Core:Every processor is divided internally into units called as 'cores'
        Each core can execute instruction from one "Process" at the given time//how many processes can be executed parallely

        6)Process : A running task on a system.


        time  ./app//give the how much time is taking by each function in the program

         g++ -lpthread ->library to work with



*/


#include<iostream>
#include<vector>
#include<functional>
#include<thread>
#include<array>

using Operation=std::function<int(int number)>;
using Array=std::array<int,10>;

Array result{0};


int Adaptor(Operation fn,std::vector<int>& data){
    int k=0;
    for(int val: data){
        std::this_thread::sleep_for(std::chrono::seconds(1));
        result[k++] = fn(val);//apply function on a single item,Repeat this in a lopp
    }
}

int Square(int number){
    return number*number;
}

int mian(){
    auto cube_fn=[](int number){return number*number*number;};
    //execute Adaptor function by using square funvtion and vector of values as it's parameters
    std::thread t1{&Adaptor,&Square,std::vector<int>{1,2,3,4,5},0};

    std::thread t2{Adaptor,cube_fn,std::vector<int> {1,2,3,4,5},5};


    t1.join();//main cannot proceed beyond line 56 unless t1 is terminated/completed
    t2.join();////main cannot proceed beyond line 57 unless t2 is terminated/completed

    for(int val:result){
        std::cout<<val<<"\n";
    }
}
/*
void Adaptor(Operation fn,std::vector<int>& data){
    for(int val: data){
        std::this_thread::sleep_for(std::chrone::seconds(1));
        fn(val);//apply function on a single item,Repeat this in a lopp
    }
}

void Square(int number){
    std::cout<<number*number<<"\n";
}

int mian(){
    auto cube_fn=[](int number){std::cout<<number*number*number;};
    //execute Adaptor function by using square funvtion and vector of values as it's parameters
    std::thread t1{&Adaptor,&Square,std::vector<int>{1,2,3,4,5}};

    std::thread t2{&Adaptor,cube_fn,sta::vector<int> {1,2,3,4,5}};

    Adaptor(Square,std::vector<int>{1,2,3,4,5});

    Adaptor(cube_fn,std::vector<int>{1,2,3,4,5});

    t1.join();//main cannot proceed beyond line 56 unless t1 is terminated/completed
    t2.join();////main cannot proceed beyond line 57 unless t2 is terminated/completed
}

*/