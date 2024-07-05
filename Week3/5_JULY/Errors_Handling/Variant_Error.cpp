#include<iostream>
#include<variant>
#include<list>

int main(){
    std::list<std::string> data{10,20,30,40};
}

// "std::__cxx11::list<_Tp, _Alloc>::list [with _Tp=std::string, _Alloc=std::allocator<std::string>]" 
// no instance of constructor matches the argument `
/*
                Topics for marathon
concurrency:

std:thread
    -join,joinable,mutex,lock_gourd,unique_lock
    -std::async_threads
cpp17:
    std::variant
    std::optional
    -guranted copy __cpp_guaranteed_copy_elision
    -if in it
    -structure binding
    -singleton class

    
Supplementry
    -unique ptr
    -shared ptr

*/