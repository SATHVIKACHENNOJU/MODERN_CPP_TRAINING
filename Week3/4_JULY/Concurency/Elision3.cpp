#include<iostream>

class Data
{
private:
    int m_value{0};
public:
    Data()=default;
    ~Data()=default;

    Data(const Data&)=delete;
    Data(Data&&)=default;
    Data& operator=(const Data&)=delete;
    Data& operator=(Data&&)=delete;


    explicit Data(int val):m_value{val}{}

    friend std::ostream &operator<<(std::ostream &os, const Data &rhs) {
        os << "m_value: " << rhs.m_value;
        return os;
    }
    

};


Data Creator(){
    return Data{100};

}

// void Absorber(Data d1){
//     std::cout<<d1<<"\n";
// }

Data Absorber(Data d1){
    std::cout<<d1<<"\n";
    return d1;
}

int main(){
    Absorber(Creator());//d1 will be created inside Absorber and remains there till end

    Data obj=Absorber(Data{100}); //works when return type of abso is Data and return d1 use is no copy constructor used 
    //compiler converts this to Data obj {100};
    std::cout<<"Object is in main:"<<obj<<"\n";

    //all the purpose of this is some times compiler will bypass the copy and seek some other way to do the things
}