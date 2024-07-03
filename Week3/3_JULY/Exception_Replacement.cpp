#include<iostream>
#include<optional>//cpp17(simply a variant with 2 only 2 states value present or not)
/*

    16 binary bits can generate a total of 2^16==65536(by 2)

    -32768   0        32767

*/
/*size_t Fatorial(int16_t val){
    if (val<0){
        throw std::invalid_argument("negative number!");
    }
    else if(val==0||val==1){
        return 1;
    }
    else {
        size_t total{1};
        for(size_t i=2;i<=val;i++){
            total*=i;
        }
        return total;
    }
} 
// factorial takes 1 init16_t by value and optionally returns a size_t(someties,not always)
// factorial function may or may not return a value

int main(){
    try{
        Fatorial(10);
    }
    catch(std::invalid_argument& ex){
        std::cerr<<ex.what()<<"\n";
    }
    try{
        Fatorial(-5);
    }
    catch(std::invalid_argument& ex){
        std::cerr<<ex.what()<<"\n";
    }
}
*/
std::optional<size_t> Fatorial(int16_t val){
    if (val<0){
        return std::nullopt;//a symbolic data value to indicate "NULL"
    }
    else if(val==0||val==1){
        return 1;
    }
    else {
        size_t total{1};
        for(size_t i=2;i<=val;i++){
            total*=i;
        }
        return total;
    }
} 

int main(){
    if(std::optional<size_t> result=Fatorial(-5);result.has_value()){
         std::cout<<"Factorial is:"<<result.value();
    }
    // if(result.has_value()){
       
    // }

    else{
        std::cerr<<"Factorial did not return a value\n";
    }
}


/*
define a function which takes a value 
if value is negative,I have nothing to return 
else if value is 0 or 1 ,I should return 1

else{
do a product of 2...value.Return the total
}

main code is:

call the function with a value ,we may get a "suprise" box!

if(suprise box has a value, print the value)

else{
show a error message saying "I got nothing in the suprise box"}
*/