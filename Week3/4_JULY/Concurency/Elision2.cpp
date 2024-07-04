
#include <iostream>
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



Data Magic(){
  //return Data{100};
  Data obj=Data{100};
  return obj;//works if move is enabled 
}

int main(){
   Data d1=Magic();

}