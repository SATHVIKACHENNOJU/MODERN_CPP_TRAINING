#include<iostream>
#include<vector>
#include<variant>
//variants(algibric/abstract data type) are categorical types which allows  "either or " type principle of typing 
int main(){
    int32_t n1{100};
    std::string s1{"Sathvika"};

   // std::vector<std::string> v1{n1,s1};
   std::variant<int32_t,std::string> vr;

   vr=n1;
   std::cout<<"variant is working\n";
   vr=s1;

   vr=41.45f;
}

/*

//similar to unions concept of c laguage here in vr 2 slots are there 1 for int 1 for string but as string is highest it will allocate string size block

vr=n1
    int32_t   std::string    index variable
[      10     |  xxxxxx   |              0               ]//24 bytes(we can use first 4 to store int remainig 20 to string or all 24 for string)


vr=n1

    int32_t     std::string         index_variable
[   10        |     sathvika     |      1   ]//24 byte





*/