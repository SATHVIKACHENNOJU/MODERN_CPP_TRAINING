/*

    Magic                          
                                 Heap
                                 Employee
    ptr[0x100H]------------>[101|Sathvika|9000.0f]

    void Magic(){

    //Employee* ptr=new Employee(101,"Harshit",900.0f);

    Wrapper wr{new Employee(101,"Sathvika",900.0f);};

    if(condition){
   // std::cout<<*ptr<<"\n";
    //delete ptr;
    std::cout<<wr.get()<<"\n";
    }
    else{
    throw MyException("Something went wrong!");
    //delete ptr;//non-rechable code
    }
    }//exit from here after if!

    int main(){
    
    Magic();
    int n1=10;

    }


*/

#include<iostream>
#include<list>

void CreateData(std::list<int>& data){

    data.emplace_back(10);
    data.emplace_back(20);

}
void CalculateTotal(std::list<int>& data){
    if(data.empty()){
        throw std::invalid_argument("empty data");
    }

    float total{0.0f};
    for(int val:data)
        {
            total+=val;
        }
    std::cout<<"Total is:"<<total<<"\n";
}

void PrintFirstElement(std::list<int>& data){
    if(data.empty()){
        throw std::invalid_argument("empty data");
    }

    std::cout<<data.front();
}
int main(){

    std::list<int> data{};
    CreateData(data);
    CalculateTotal(data);
    PrintFirstElement(data);
    //we will exit from the main function (list class is smart enough to handle the heap allocation adn delete the memory allocated when distructor is called )

    
}