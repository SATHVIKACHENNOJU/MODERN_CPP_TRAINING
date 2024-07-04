/*


    1)CreateCarsAndOBikess
    2)FindAverageCostOfVehicles : return/print the average price of all the vehicles in our database
    3)ReturnMatchingInstance : return the first vehicle whose Id matches with the recived Id Parameter
    4)Deallocate:release heap allocations if any!
    5)DisplayInsuranceAmount:show output of insuranceAmount function for each instance
    6)FindCOuntForGivenId : fetches vehicle based on ID and returns corresponding seat_count




*/

#include<variant>
#include<optional>
#include<list>
#include<iostream>
#include"Car.h"
#include "Bike.h"
#include<thread>
#include<mutex>

using VrType=std::variant<Car*,Bike*>;
using DataContainer=std::list<VrType>;
using ThreadContainer=std::list<std::thread>;

class Operations
{
private:
    static DataContainer m_data;
    static ThreadContainer m_threads;
    static std::mutex mt;
public:
    Operations(/* args */) =delete;
    ~Operations() =default;
    Operations(const Operations&)=delete;
    Operations(Operations&&)=delete;
    Operations& operator=(const Operations&)=delete;
    Operations& operator=(Operations&&)=delete;

    static void CreateCarsAndBikes();//DataContainer& data, no need to send container form outside as it is readliy available inside class under private section


    /*
    FindAverageCost : use visit function to do this.Bath car and bike have a m_price attribute,we can use their getter functions to calculate total
    */

   static void FindAverageCost();

   static std::optional<VrType> ReturnMatchingInstanc(std::string id);

   static void Deallocate();

   static void DisplayInsuranceAmount();


   /*
    Scenarios:
    1->Id found matches with a car seat count returned
    2->id found matches with a bike --->nullopt
    3->id not found --->nullopt
   
   */

  static std::optional<unsigned int> FindCOuntForGivenId(std::string id);

  DataContainer data() const { return m_data; }

  static void setData(const DataContainer &data) { m_data = data; }

  static void MapThreads();

  static void JoinThreads();


  
};