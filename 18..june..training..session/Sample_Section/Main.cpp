#include "functionalities.h"

int main()
{
    unsigned int n;
    std::cin >> n;
    Engine *arr[n];
    CreateEngines(arr, n);
    std::cout << "The average horse power is:" << AverageHorsePower(arr, n) << "\n";
    try
    {
        float f{0.0f};
        f = FindTorqueById(103, arr, n);
        std::cout << "Torque of the given id id:" << f << "\n";

        f = FindTorqueById(108, arr, n);
        std::cout << "Torque of the given id id:" << f << "\n";
    }
    catch (IdNotFounException e)
    {
        std::cout << "Invalid Id\n";
    }
    std::cout << "HorsePower For Minimum Torque Engine is:" << FindHorsePowerForMinTorqueEngine(arr, n) << "\n";
    std::cout<<"Sum of torque of 101 and 102 are:"<<*arr[0]+*arr[1]<<"\n";
    PrintObjects(arr,n);
    deallocate(arr, n);
    return 0;
}