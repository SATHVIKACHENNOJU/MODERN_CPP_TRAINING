/*

///////

main(){
bool flag fn();
if(flag){
//
}
else
{
//////
}//flag should be earesed at the end of this line

    ///flag is gone 

}



*/

#include<iostream>
#define sathvika main 
bool CheckDivisibilityBy3(int32_t number){
    return number%3==0;
}

int sathvika(){
    int32_t n1{10};
    //if flag variable is initialized and then flag is also true
    if( bool    flag=CheckDivisibilityBy3(n1);flag){
        std::cout<<"number is devisible by 3";

    }
    else{
        std::cerr<<"flag is set at:"<<std::boolalpha<<flag<<"\nnumber not divisible by 3\n";
    }

    //std::cout<<"Cannot access flag now"<<flag;//generate error as flag scope is ended after else block
}