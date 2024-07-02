#include<iostream>
#include<thread>
#include<mutex>
class MathOperation
{
private:
    std::mutex mt;
    int32_t m_value{0};
public:
    MathOperation(const MathOperation&) =delete;
    MathOperation(MathOperation&&)=delete;
    MathOperation& operator=(const MathOperation&)=delete;
    MathOperation& operator=(MathOperation&&)=delete;
    MathOperation()=default;
    MathOperation(int val) : m_value{val}{}
    ~MathOperation()=default;

    void square(){
        mt.lock();
        std::cout<<"ID:of the thread square:"<<std::this_thread::get_id()<<"\n";
        std::cout<<"square of"
        <<m_value<<" is"<<m_value*m_value;
        mt.unlock();

    }

    int32_t addition(int other){
        mt.lock();
        std::cout<<"ID:of the thread addition:"<<std::this_thread::get_id()<<"\n";
        mt.unlock();
        return m_value+other;
        };

    //paren paren operator
    int64_t operator()(){
        mt.lock();
        std::cout<<"ID:of the thread square:"<<std::this_thread::get_id()<<"\n";
        mt.unlock();
        return m_value*m_value*m_value;
    }
};

//an object that behaves like a function (can be invoked like a function)
//is called a "function" object
int main(){

 //   std::thread t1 {&MathOperation::square,MathOperation{10}};
    

    MathOperation m1{100};
    std::thread t1 {&MathOperation::square,&m1};

    std::thread t2{std::ref(m1)};//thread will put the bracket after m1 and try to call it as a function as we overloaded ( ) or else it will generate erro r

    std::thread t3{&MathOperation::addition,&m1,100};
    //you cannot capture return values from a function when executing them via std::thread

    //m1();//use the paranthesis operator with the object

    t1.join();
   // t2.join();
    t3.join();

    //t2 and t3 output will get discarded no matter what 
}