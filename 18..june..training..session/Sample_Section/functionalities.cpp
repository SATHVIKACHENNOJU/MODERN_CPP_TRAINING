#include "functionalities.h"

void CreateEngines(Engine **arr,unsigned int n){
    int id,hs;
    float t;
    for(int i=0;i<n;i++)
    {
        std::cin>>id>>hs>>t;
        arr[i]=new Engine(id,hs,t);
    }
}

int AverageHorsePower(Engine **arr,unsigned int n){
    unsigned int sum=0,c=0;
    for(int i=0;i<n;i++)
    {
    if(arr[i]){
        sum+=arr[i]->getHorsepower();
        c++;
    }
    }

    return sum/c;
}

float FindTorqueById(unsigned int id,Engine **arr,unsigned int n){
    float t=0.0f;
    int f=1;
    for(int i=0;i<n;i++)
    {
        if(arr[i]->getId()==id){
            t=arr[i]->getTorque();
            f=0;
            break;
        }

    }
    if(f)
    throw IdNotFounException("Id not found");
    return t;
    
}

int FindHorsePowerForMinTorqueEngine(Engine **arr,unsigned int n){

    float min=arr[0]->getTorque();
    for(int i=0;i<n;i++)
    {
        if(arr[i]->getTorque()<min)
        {
        min=arr[i]->getTorque();
        
        }
    }
    return min;
}

void PrintObjects(Engine **arr,unsigned int n)
{
    for(int i=0;i<n;i++)
    {
        std::cout<<*arr[i]<<"\n";
    }
}

void deallocate(Engine **arr,unsigned int n){
    for(int i=0;i<n;i++)
    {
        delete arr[i];
    }
}