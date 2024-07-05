
#include<iostream>
#include<memory>

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



void Magic(std::unique_ptr<Data> temp){

}

//std::unique_ptr<Data> ReturnFirstObject(DataContainer& data);->this also don't work as it is equavilent to copy

int main(){
    
   std::unique_ptr<Data>ptr4{new Data{100}};

   //std::unique_ptr<Data>ptr5{ptr4};-->as copy constructor is deleted this will not work even it is not possible to pass ptr4 by value to any functiom now
    //Magic(ptr4);->not works
   //since move id not deleted we can trigger a move operation as follow

   //Magic(std::move(ptr4));

   //we cannot use ptr4 now as it is moved to  somewhere else from here

   //ptr4.reset{new Data{99}};->now as we resetted it we can use it aga
}


//so unique pointer cannot be used for copy in any possible way we cannot pass by value....and so on ,so by using unique pointer we can write a solid code which strictly probhit the copy