#include "Engine.h"
#include "IdNotFounException.h"
//#define SIZE 5
void CreateEngines(Engine **arr,unsigned int n);

int AverageHorsePower(Engine **arr,unsigned int n);

float FindTorqueById(unsigned int id,Engine **arr,unsigned int n);
int FindHorsePowerForMinTorqueEngine(Engine **arr,unsigned int n);
void PrintObjects(Engine **arr,unsigned int n);
void deallocate(Engine **arr,unsigned int n);

/*Instead of passing size all the time make it global variable so we can eliminate all the size parameters*/