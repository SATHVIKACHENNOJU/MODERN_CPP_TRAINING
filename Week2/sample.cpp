/*
    create an adaptor which accepts

    a)a data container of string values
    b)a function with the following signature
        i)input parameter : one string by lvalue reference
        ii)output:void

        Adaptor should be used to perform operations on string values
        which are

        1)identify vovels
        2)print the last 3 characters of each string
        3)print the first non-vowel character of each string
*/

#include<iostream>
#include<functional>
#include<vector>

//creating aliases
using datacontainer=std::vector<std::string>;
using Logic=std::function<void (const std::string&)>;

//declaring and defining adapter logic here

void Adaptor(const Logic fn,const datacontainer& data){
    if(data.empty())
    {
        std::cerr<<"Container is empty!!!\n";
    }
    for(const std::string& st:data){
        fn(st);
    }
}
void FindVowels(const std::string& val){
    if(val==""){
        std::cerr<<"cannot find vowels on a blank string\n";
        return;
    }
    bool atleastOneVowelFound{false};
    for( const char c : val){
        if(c =='A'||c =='a'|| c=='E'||c=='e'||c=='I'||c=='i'||c=='O'||c=='o'||c=='U'||c=='u'){
            atleastOneVowelFound=true;
            std::cout<<c<<"\n";
        }
    }
    if(!atleastOneVowelFound){
        std::cerr<<"No vowels found\n";
    }
}
//client code

//demonstarte adapter here

int main(){

    std::vector<std::string> data1{"","abc","xyz","mno"};
    std::vector<std::string> data2{"","",""};
    std::vector<std::string> data3{};

    try{
        Adaptor(&FindVowels,data1);
        Adaptor(&FindVowels,data2);
        Adaptor(&FindVowels,data3);
    }
    catch(std::invalid_argument& ex){
        std::cerr<<ex.what()<<"\n";
    }

    //Adaptor([](const std::string& st) {std::cout<<st.length();});
}

