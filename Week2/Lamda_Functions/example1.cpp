/*

    More about lambdas :

        1)WHAT ARE THEY EXACTLY?
        2)WHAT IS [] WITH LAMBDAS?
            if we want to access objects/variables created in enclosing function of 
            lambda we use
        3)SOME WEIRD THINGS TO KNOW ABOUT LAMBDAS

    What compiler does with lambda?
        1)create a class with "some" name

        class _Lambda$1{
        
        private:
        
        Public:
        
        operator()
        
        }
        _Lambda$1 obj{};

        obj();//operator object


*/


#include<iostream>
#include<functional>
void Demo(void(*ptr)(int n1,int n2)){
    ptr(10,20);
}
int main(){
    auto fn=[](int n1,int n2){std::cout<<n1+n2;};
    //Demo(&fn);//don't work
    Demo(+fn);//works(+ alllows you convert the lambda into function pointer)
}


/*
void add(int32_t n1,int32_t n2){
    std::cout<<n1+n2<<"\n";
}


auto fn=[](int32_t n1,int32_t n2){std::cout<<n1+n2<<"\n";};
//main is the outer box in which lambda exist so we say that main is a enclosing function of lambda
int main(){
     
    //lambda object is bound to fn variable in main function
    
   int data=20;
   int value=30;
   //auto fn=[](int32_t n1,int32_t n2){std::cout<<n1+n2+data<<"\n";};//lambda is a function which can't accsess the data var out side its scope

    auto fn=[data](int32_t n1,int32_t n2){std::cout<<n1+n2+data<<"\n";};
    //auto fn=[data,value](int32_t n1,int32_t n2){std::cout<<n1+n2+data<<"\n";};
   fn(10,20);//overloaded () operator of a class created in the background
   //fn(10,20),data;//data can be passed as additional parameter
}*/

/*
Capture clause

int n1=10;
int n2=20;
int n3=30;

example 1:use of no captured variables
    auto fn=[](){std::cout<<"Hello world!";};
    fn();
example 2:use of no captured variables but passed parameters

    auto fn=[](){std::cout<<n1+n2;};

    fn(n1,n2);

example 3:use n1 as capatured variable,n1 should be copied into the lambda

    auto fn=[n1](int n2){std::cout<<n1+n2;};
    fn(n2);//only n2 is passed as we alredy captured n1

example 4:use n1 as captured variable,n1 should be referred into the lambda
    auto fn=[&n1](int n2){std::cout<<n1+n2};
    fn(n2);//only n2 is passed as n1 is already captured by reference

example 5:capture all variable from the surroundings (make them all accessible in the lamda),(copied 
everything into the lambda when they are accessed in the body of the lambda)

auto fn=[=](){std::cout<<n1+n2+n3;};

fn();//all variables were copied by capture into the lambda

="capture the variable and make them constant so we can't modify them util they are passed by reference"

auto fn=[&](){std::cout<<n1+n2+n3;};
fn();//all variables were captured by reference into the lambda
*/