#include<iostream>
#include<vector>


void deallocate(std::vector<int*>&& values){//rvalue reference
    for(int* v:values){
        delete v;
    }
}
void Magic(std::vector<int*>&& values){
    for(int* v : values){
        std::cout<<*v<<"\n";
    }
    deallocate(std::move(values));//transfering the ownership of heap allocated data
}



int main(){
    std::vector<int*> data{new int(10),new int(20)};

    Magic(std::move(data));//transfer ownership of heap allocated data
}

//accessing data variable after move is complete
//WILL BE UNIFIED BEHAVIOUR