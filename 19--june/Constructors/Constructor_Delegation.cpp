#include<iostream>

enum class Rating{
    _5_STAR,
    _4_STAR,
    _3_STAR,
    _2_STAR,
    _1_STAR,
    _NO_RATING
};

class Car{
    private:
    unsigned int m_id{0};
    float m_price{0.0f};
    Rating m_safteyRating{Rating::_NO_RATING};
    public:
    /*Constructor Delegation: when have constructors with different parameters if we call constructor with 2 parameters ,first it will go
    to constructor with 2 parameters first then map to constructor with 3 parameters these new feature will avoid the data duplication
    (simplay this means initializing a object using multiple constructors-the things is instead of list initilization use mapping in constructor with more parameters
    The destructor must be set to default to allow these feature to work)
    */
   // Car(unsigned int id,float price):m_id{id},m_price{price}{}
   Car(unsigned int id,float price):Car(id){
    m_price=price;
   }
    Car(unsigned int id,float price,Rating rating):Car(id,price){
        m_safteyRating=rating;
    }
    Car(unsigned int id):m_id{id}{}
    Car()=delete;
    Car(const Car&)=delete;
    Car& operator=(const Car&)=delete;
    Car& operator=(Car&&)=delete;
    Car(Car&&)=delete;
    ~Car()=default;
};

int main(){
    Car c1(101,1000.0f,Rating::_5_STAR);
    Car c2(102,1067.0f,Rating::_4_STAR);
}
