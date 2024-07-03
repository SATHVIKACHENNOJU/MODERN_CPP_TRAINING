#include<iostream>
#include<list>
#include<thread>
#include<mutex>

/*static data members are not initiakized inside the class as constructors also not able to initilize them
a static memeber can only be modified insized the static method of the class and we initilize them outside class.


to make a class to contain only 1 single object steps:(singleton(design pattern used in different scenarios(Design patterns are solutions for common problems)) : disabling the user from creating multiple objects)
1)make all the counstructors private(to disable them)
2)create a class type static variable to access class members and create one single object


*/


using ThreadContainer = std::list<std::thread>;
class BankOperations
{
private:
    int32_t m_amount{1000};
    std::mutex mt;

public:

    void Deposit(){
    for(int i=0;i<100;i++){
        std::this_thread::sleep_for(std::chrono::milliseconds(5));
        mt.lock();
        m_amount+=10;
        mt.unlock();
    }
}

void Withdraw(){
    for(int i=0;i<100;i++){
        std::this_thread::sleep_for(std::chrono::milliseconds(2));
        mt.lock();
        m_amount-=10;
        mt.lock();
    }
}

    BankOperations(int32_t val):m_amount{val}{}
    ~BankOperations()=default;

    int32_t amount() const { return m_amount; }
};

void CreateThreads(ThreadContainer& threads,BankOperations& b1){
    threads.emplace_back(&BankOperations::Deposit,&b1);
    threads.emplace_back(&BankOperations::Withdraw,&b1);

}
void JoinThreads(ThreadContainer& threads){
    for(std::thread& th:threads){
        if(th.joinable()){
            th.join();
        }
    }

}
void DisplayFinalAmount(BankOperations& b1){
    std::cout<<"Final answer is:"<<b1.amount()<<"\n";
}

int main(){
    BankOperations b1{5000};

    ThreadContainer threads{};//blank list of threads

    CreateThreads(threads,b1);

    JoinThreads(threads);

    DisplayFinalAmount(b1);

}