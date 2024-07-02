#ifndef ENGINE_H
#define ENGINE_H

#include<iostream>

class Engine
{
private:
    unsigned int id{0};
    unsigned int horsepower{0};
    float torque{0.0f};
public:
    Engine()=default;
    ~Engine();
    Engine(const Engine& other)=delete;//copy
    Engine(Engine&& other)=delete;
    Engine &operator=(const Engine other)=delete;
    Engine operator=(Engine &&other)=delete;
    Engine(unsigned Id,unsigned int hp,float t);
    unsigned int getHorsepower() const { return horsepower; }
    void setHorsepower(unsigned int horsepower_) { horsepower = horsepower_; }

    unsigned int getId() const { return id; }
    void setId(unsigned int id_) { id = id_; }

    float getTorque() const { return torque; }
    void setTorque(float torque_) { torque = torque_; }
    float operator +(const Engine &e2);
    friend std::ostream &operator<<(std::ostream &os, const Engine &rhs);
};

#endif // ENGINE_H
