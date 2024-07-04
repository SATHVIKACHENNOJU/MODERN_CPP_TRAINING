/*

    elsision : not do something,not perform somrthing,
    ignore/avoid something


    guranteed copy ELision:cpp17



*/


#include <iostream>
class Data
{
private:
    int m_value{0};
public:
    Data()=default;
    ~Data()=default;

    Data(const Data&)=delete;
    Data(Data&&)=delete;
    Data& operator=(const Data&)=delete;
    Data& operator=(Data&&)=delete;
   // Data(int val):m_value{val}{}

    explicit Data(int val):m_value{val}{}//explicit marked constructors will not be used for auto type conversion by compiler

   

    friend std::ostream &operator<<(std::ostream &os, const Data &rhs) {
        os << "m_value: " << rhs.m_value;
        return os;
    }
    

};


//void Magic(Data &d1){//as copy constructor is disabled we cannot pass r vaue such as 10 100 so wee neww makw it pass by referance
void Magic(Data d1){
    std::cout<<d1<<"\n";
}

int main(){
    Data d1{100};

   // Magic(d1);->this will not work as copy is disabled
   // Magic(  Data{20} ); works if void Magic(Data d1) (this just a attachment temporarly not copy or move so that we cannot use it using pass by reference )

   //Magic(100);->wii not work because conversion is disabled (explicit
   //
    Data d2{'A'};
  // Magic(d2);

  Magic(Data{100});//an rvalue of type Data is used to indicate an object of type Data
                    //compiler simply refactors/modifies the code as Data d1{100}
}