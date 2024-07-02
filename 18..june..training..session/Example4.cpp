#include<iostream>

// case 1:void Magic(int n1){

// }works with both call

//case 2: only works with second call first not works
// void Magic(int& data){

// }


// case 3:void Magic(const int& data){

// }
//case 4: both calls accepted -- this will allow to move the data
void Magic(const int&& data){

}
int main(){
    Magic(10);
    int n1=10;
    Magic(n1);
}