#include<iostream>
#include<thread>


void Formula(int val,float factor,const std::string& name){
    std::cout<<"Absolutely important work:";
}

int main(){
    int n1{10};
    std::thread t1{&Formula,n1};
}

/*the arguments we sent through directly not go to thread instead they got forwarded through a middle man.
Perfect forwarding:accepts infinite number of arguments*/