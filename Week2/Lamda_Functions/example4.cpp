#include<iostream>
#include<vector>
void Magic(int& data){

}

int main(){
    int n1=10;
    int& ref=n1;//ref is a reference to n1

    //ref is an alternative name for n1 in main function

    Magic(n1);//int& data = n1;

    std::reference_wrapper<int> arr[1] {ref};
    std::vector<std::reference_wrapper<int>> v1;

    std::cout<<v1[0].get();
  //  int& arr[1]{ref};--won't work because logically it's not 
  //possible to make arry for something with 0 memory and here ref
  // is just a reference variable which is an alias for n1 and logically 
  //no memory allocated for it

}