#include "Engine.h"
#include "IdNotFounException.h"
#include "NoValidEngineFoundException.h"
#include <vector>
using container=std::vector<Engine*>;
//#define SIZE 5
void CreateEngines(std::vector<Engine*>& arr);

int AverageHorsePower(const std::vector<Engine*>& arr);

float FindTorqueById(unsigned int id,const std::vector<Engine*>& arr);
int FindHorsePowerForMinTorqueEngine(const std::vector<Engine*>& arr);
void PrintObjects(const std::vector<Engine*>& arr);
void deallocate(const std::vector<Engine*>& arr);
/*Instead of passing size all the time make it global variable so we can eliminate all the size parameters*/