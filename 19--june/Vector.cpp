#include<iostream>
#include<vector>
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
    Car(unsigned int id,float price):Car(id){
    m_price=price;
    }
    Car(unsigned int id,float price,Rating rating):Car(id,price){
        m_safteyRating=rating;
    }
    Car(unsigned int id):m_id{id}{}
    Car()=delete;
    Car(const Car&)=default;
    Car& operator=(const Car&)=delete;
    Car& operator=(Car&&)=delete;
    Car(Car&&)=delete;
    ~Car()=default;
};

int main(){
   /* Car c1(101,1000.0f,Rating::_5_STAR);
    Car c2(102,1067.0f,Rating::_4_STAR);*/

/*Here even this is technically good we are copying the data and making task with worst optimality to get optimal memory and good solution create objects inside vector itself*/
   // std::vector<Car> cars{c1,c2};
    //the above line will not work as we disabled copy constructor to make it work:
    //option 1: Enable copy constructor
    //option 2: Move Constructor- moving cars(not applicable in this context)
    //option 3:Create the data inside the vector directly(technically called "emplacing")
    std::vector<Car> cars;
    cars.emplace_back(101,10000.0f,Rating::_1_STAR);
    cars.emplace_back(102,20000.0f,Rating::_2_STAR);
    /*this is the most optimal way of memory utilization insted of copying and moving*/

    //as vector is a ready made library function it gives us many functionalities

    std::cout<<"No of elements in the vector currently:"<<cars.size()<<".\n";//the return type of this function is unsigned long which we call size_t
}
