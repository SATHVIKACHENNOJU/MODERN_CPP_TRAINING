#include<iostream>
#include<thread>
#include<vector>
#include<functional>
#include<mutex>//oridinary,binary semaphore

std::mutex mt;
using Operation=std::function<int(int number)>;


void Adaptor(Operation fn,std::vector<int>& data){
    for(int val: data){
        std::this_thread::sleep_for(std::chrono::seconds(1));
        fn(val);//apply function on a single item,Repeat this in a lopp
    }
}

void Square(int number){
    mt.lock();//ask permission to access cout
    std::cout<<number*number<<"\n";//critical section
    mt.unlock();//release the lock when done
}

int mian(){
    auto cube_fn=[](int number){
        mt.lock();
        std::cout<<number*number*number;
        mt.unlock();};
    //execute Adaptor function by using square funvtion and vector of values as it's parameters
    std::thread t1{&Adaptor,&Square,std::vector<int>{1,2,3,4,5}};

    std::thread t2{&Adaptor,cube_fn,std::vector<int> {1,2,3,4,5}};

   // Adaptor(Square,std::vector<int>{1,2,3,4,5});

    //Adaptor(cube_fn,std::vector<int>{1,2,3,4,5});

    t1.join();//main cannot proceed beyond line 56 unless t1 is terminated/completed
    t2.join();////main cannot proceed beyond line 57 unless t2 is terminated/completed
}
