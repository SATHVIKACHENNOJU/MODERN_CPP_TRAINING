#include "functionalities.h"

int main()
{
    // unsigned int n;
    //std::cin >> n;
    std::vector<Engine*> arr;
    CreateEngines(arr);
    try{
    std::cout << "The average horse power is:" << AverageHorsePower(arr) << "\n";
    }
    catch(NoValidEngineFoundException e1){
        std::cout<<"No valid Engine found\n";
    }
    try
    {
        float f{0.0f};
        f = FindTorqueById(103, arr);
        std::cout << "Torque of the given id id:" << f << "\n";

        f = FindTorqueById(108, arr);
        std::cout << "Torque of the given id id:" << f << "\n";
    }
    catch (IdNotFounException e)
    {
        std::cout << "Invalid Id\n";
    }
    std::cout << "HorsePower For Minimum Torque Engine is:" << FindHorsePowerForMinTorqueEngine(arr) << "\n";
    std::cout<<"Sum of torque of 101 and 102 are:"<<*arr[0]+*arr[1]<<"\n";
    PrintObjects(arr);
    deallocate(arr);
    return 0;
}