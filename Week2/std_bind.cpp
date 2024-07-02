/*
std::bind allows us to "refactor"/"repurpose"/"remodel" an existing function to create
"partially-implemented" functions.
*/
/*
    cp -r source destination----->in linux we always give like this
    
    in c:
    strcpy(desitination,source);

    old parameter sequence(sr.no,state,duration,after-duration_state)
    new parameter sequence(sr.no,duration,state,after-duration state)


    bind is like the partial implemented functions of mathematics:

    ex: g(x) is a partial function implemented on f(x,y) where y is 4
*/


#include<iostream>
#include<functional>

void formula(int x,int y,int z){
    std::cout<<((x+y)-z);
}

int main(){
    formula(100,20,30);
    //formula(30,10,20);

    auto partial_formula = std::bind(&formula,100,std::placeholders::_1,std::placeholders::_2);
    //x value is set to 100 as extra value and value provieded 2nd will go to 1st and 3rd mapped to 2nd location
    
    partial_formula(20,30);//formula(100,20,30)

    auto swapped_formula=std::bind(&formula,std::placeholders::_2,std::placeholders::_3,std::placeholders::_1);
    swapped_formula(10,20,30);//formula(20,30,10)

    auto weirdly_mapped_formula=std::bind(&formula,100,200,std::placeholders::_2);

    weirdly_mapped_formula(99,100);//99 is discarded because _1 was not usd


}