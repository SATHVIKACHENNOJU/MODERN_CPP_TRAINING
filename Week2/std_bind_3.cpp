#include<iostream>
#include<functional>

class Data{
    private:
        int m_value{0};
    public:
        Data()=default;
        Data(const Data&)=delete;
        Data(Data&&)=delete;
        Data& operator =(Data&&)=delete;
        Data& operator=(const Data&)=delete;
        ~Data()=default;

        Data(int val):m_value{val}{}

        void DisplayReading(int factor){
            std::cout<<m_value*factor<<"\n";
        }

        static void Diaplay(int times){
            std::cout<<"HelloWorld"<<times<<" Times\n";
        }
};

int main(){
    Data obj{18};//m_value is 19

    obj.DisplayReading(100);//100 is the factor
    auto fn=std::bind(&Data::DisplayReading,&obj,100);
    fn();//obj.DisplayReading(100);
    Data::Diaplay(10);//static functions can be directly called by class name not using objs
    auto binded_static_display=std::bind(Data::Diaplay,10);
    binded_static_display();//Data::Display(10)

    /*
    For non static member functions
    a)objects address is mandatory
    b)it must be the first argument after specifying the name of the function in bind
    c)you "must" use & symbol with the name of the member function in bind

    for static member functions

    a)No object involved so no address required
    b)you "SHOULD NOT" use & symbol with the name of the function
    
    */
}