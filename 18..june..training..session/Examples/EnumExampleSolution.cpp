/*
problems with regular enums
*/
//all the problems are solved using enum class so that's why we are getting errors
#include<iostream>

enum class Gear{
    FIRST,
    SECOND
};

enum class Rank{
    FIRST,
    SECOND
};
void Magic(int n1){
    std::cout<<n1*100;
}
int main(){
    FIRST;//Not mandatory to prefix enum naem(confusion)

    Gear g1=Gear::FIRST;
    Rank r1=Rank::FIRST;
//comparing rank with gear logical don't make any sense but this line executes which is a bad thing
    if(g1==r1)//problem2:enum of 2 different categories get compared on basis of integer values
    {
    std::cout<<"OOOOOOF NO!!!\n";
    }

    Magic(r1);//problem 3:auto conversion of enum to integer without conset
}