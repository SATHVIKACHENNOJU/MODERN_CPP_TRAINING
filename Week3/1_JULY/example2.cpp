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
