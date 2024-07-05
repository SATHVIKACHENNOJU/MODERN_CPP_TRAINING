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

int main(){
    std::unique_ptr<int>ptr1{(int*)malloc(4)};//using c syntax
    std::unique_ptr<int>ptr2{new int()};//using cpp syntax
    std::unique_ptr<char>ptr3{(char*)malloc(4)};
    //creating a smart pointer for a class
    std::unique_ptr<Data>ptr4{new Data{100}};

    /*
    Data* d1{new Data{100}};
    std::unique_ptr<Data>ptr4{d1};

    //doing this will leads to more problems there is no memory leak and works perfectly but thing is if any body deallocates raw pointer
    delete d1;
    then we get error as doouble free detected so it a king of thing like killing the person who was already dead so switching to completely to smartpointer without using raw pointers is a good practice
    */
}