#include "Engine.h"

Engine::Engine(unsigned Id,unsigned int hp,float t) : id{Id},horsepower{hp},torque{t}{}
Engine::~Engine(){
    std::cout<<"Engine data with id:"<<this->getId()<<" is Deleted!\n";
}

std::ostream &operator<<(std::ostream &os, const Engine &rhs) {
        os << "id: " << rhs.id
           << " horsepower: " << rhs.horsepower
           << " torque: " << rhs.torque;
        return os;
    }

float Engine::operator +(const Engine &e2){
    return this->getTorque()+e2.getTorque();
}