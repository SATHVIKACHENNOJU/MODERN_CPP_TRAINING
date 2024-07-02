#include "functionalities.h"

void CreateEngines(std::vector<Engine*>& arr){
    int id,hs;
    float t;
    int n=arr.size();
    for(int i=0;i<n;i++)
    {
        std::cin>>id>>hs>>t;
        //arr[i]=new Engine(id,hs,t);
        //whatever you write in emplace_back,it should be "sufficient material"
        //to make a new instance for the container of that specific type

        //type:vector of Engine pointers--->we need materials to make a new engine
        arr.emplace_back(new Engine(id,hs,t));
    }
}

int AverageHorsePower(const std::vector<Engine*>& arr){

    float sum={0.0f};
    std::size_t validPointerCount{0};
    std::size_t n=arr.size();
    //range-based for loop(for each loop)
    for(const Engine* e : arr){
        if(e){
        //for each const Engine pointer "Called e" present in engines
        sum+=e->getHorsepower();
        validPointerCount++;
    }
    }
    /*for(std::size_t i=0;i<n;i++)
    {
    if(arr[i]){
        sum+=arr[i]->getHorsepower();
        validPointerCount++;
    }
    }*/
    if(!validPointerCount)
    throw NoValidEngineFoundException("all pointers are invalid");
    return sum/validPointerCount;
}

float FindTorqueById(unsigned int id,const std::vector<Engine*>& arr){
    float t{0.0f};
    int f=1;
    std::size_t n=arr.size();
    for(std::size_t i=0;i<n;i++)
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

int FindHorsePowerForMinTorqueEngine(const std::vector<Engine*>& arr){

    float min=arr[0]->getTorque();
    int k=0;
    std::size_t n=arr.size();
    for(std::size_t i=0;i<n;i++)
    {
        if(arr[i]->getTorque()<min)
        {
        min=arr[i]->getTorque();
        k=i;
        }
    }
    return arr[k]->getHorsepower();
}

void PrintObjects(const std::vector<Engine*>& arr)
{
    int n=arr.size();
    for(int i=0;i<n;i++)
    {
        std::cout<<*arr[i]<<"\n";
    }
}

void deallocate(const std::vector<Engine*>& arr){
    int n=arr.size();
    for(int i=0;i<n;i++)
    {
        delete arr[i];
    }
}
