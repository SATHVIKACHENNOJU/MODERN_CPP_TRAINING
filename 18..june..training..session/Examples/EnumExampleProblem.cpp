/*
problems with regular enums
*/

#include<iostream>

enum Gear{
    FIRST,
    SECOND
};

enum Rank{
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