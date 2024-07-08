#include<iostream>
#include<list>
#include<memory>

void CreateData(std::shared_ptr<int[]> arr){

    arr[0]=10;
    arr[0]=20;

}
void CalculateTotal(std::shared_ptr<int[]> arr,int size){

    float total{0.0f};
    for(int val=0;val<size;val++)
        {
            total+=arr[val];
        }
    std::cout<<"Total is:"<<total<<"\n";
}

void PrintFirstElement(std::shared_ptr<int[]> arr,int size){

    std::cout<<arr[0];
}
int main(){

    //std::list<int> arr{};
    std::shared_ptr<int[]> arr{new int[2]};
    std::cout<<arr<<"\n";
    CreateData(arr);
    std::cout<<arr<<"\n";
    CalculateTotal(arr,2);
    std::cout<<arr<<"\n";
    PrintFirstElement(arr,2);
    std::cout<<arr<<"\n";
    //we will exit from the main function (list class is smart enough to handle the heap allocation adn delete the memory allocated when distructor is called )

    
}