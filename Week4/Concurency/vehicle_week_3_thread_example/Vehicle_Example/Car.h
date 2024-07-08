#ifndef CAR_H
#define CAR_H

#include <iostream>

class Car
{
private:
    std::string m_id {""};
    float m_price {0.0f};
    unsigned int m_seat_count {0};
public:

    float InsuranceAmount();
    
    Car() = delete;
    Car(const Car&) = delete;
    Car(Car&&) = delete;
    Car& operator=(const Car&) = delete;
    Car& operator=(Car&&) = delete;
    ~Car() = default;

    Car(std::string id, float price, unsigned int count) 
        : m_id {id}, m_price{price}, m_seat_count{count} {}

    float price() const { return m_price; }

    std::string id() const { return m_id; }

    unsigned int seatCount() const { return m_seat_count; }

    friend std::ostream &operator<<(std::ostream &os, const Car &rhs);

    
    
};

#endif // Car_H
