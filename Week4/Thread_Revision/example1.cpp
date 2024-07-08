/*
    1) calculate square for 10 numbers

    10 std::thread object to compute square of number of each

    2)
    5 operations are to be performed.all are independent (order of exceution is not important).
    Execute all 5 parallely

    a)onr std::thread for each operation
    b)onr async thread for each operation
    c)mix of std::thread and std::async



    3)

    [prodeucer-consumer problem]
        |           |
        |           ^
        ^          consuming party
        data generating party

    f1(producer)-->data will be generated

    f2(consumer)-->processing data only after data is generated


    example : sensor detects collision and deployment of airbags

    program to call emergency()



*/

#include<iostream>
#include<thread>
#include<condition_variable>
#include<mutex>

int32_t value{0};
std::condition_variable cv;
std::mutex mt;
bool m_input_reviced {false};

void Producer(){
    while(!m_input_reviced)
    {
    std::cin>>value;
    if(value>5)
    {
        m_input_reviced=true;
    }
    }

    /*  data is prodeuced
        1)user input has been accepted
        2)input must be above 5

        send a signal
    */
   std::lock_guard<std::mutex> lk{mt};//is a wrapper that releases the mutex according to RAII principle
   
   cv.notify_one();
}
void consumer(){
    /*
    scenario1:consumer starts.consumer checks for condition
    if condition is false,I cannot exit the function
    */
    //waiting for signal
    std::unique_lock<std::mutex> ul{mt};

    cv.wait(ul,[](){return m_input_reviced;});
     //this value cannot be computed before producer gives a signal
    std::cout<<"Value squared is:"<<value*value<<"\n";
}
int main(){//thread
   
   //will launch producer

    std::thread t1{&Producer};

    std::thread t2{&consumer};

    std::cout<<"Main continous chilling!Ask for 15 crore to fire employees advice!!\n";
    std::cout<<"Main can literally anything!!\n";

    t1.join();
    t2.join();
   //will launch consumer

   std::cout<<"Thats all,Goodbye!\n";
}

/*
    3 perspectives

    Main Function

    a)I created t1 thread (producer)

    b)I created t2 thread (consumer)

    c)first cout

    d)second out

    e)t1 join
    
    f)t2 join

    g)good bye cout

    h)terminate app!

    producer perspective:

    a)Execute a loop, In the loop till m_input_recived is true:

        a1)took a input
        a2)checked if input is greater>5,make flag true

    b)acquire the 

*/