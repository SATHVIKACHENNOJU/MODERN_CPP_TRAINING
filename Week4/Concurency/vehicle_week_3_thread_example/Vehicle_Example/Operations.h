/*
    1) CreateCarsAndBikes
    2) FindAverageCostOfVehicles : print the average price of all vehicles in our database
    3) ReturnMatchingInstance : return the firts vehicle whose id matches with the id parameter received
    4) Deallocate : release heap allocations if any!
    5) DisplayInsuranceAmount : show output of InsuranceAmount function for each instance
    6) FindSeatCountForGivenId : fetches vehicle based on ID and returns corresponding seat_count
*/

#ifndef OPERATIONS_H
#define OPERATIONS_H

#include <variant>
#include <optional>
#include <list>
#include <iostream>
#include "Car.h"
#include "Bike.h"
#include <thread>
#include <mutex>

using VrType = std::variant<Car*, Bike*>;
using DataContainer  = std::list<VrType>;
using ThreadContainer = std::list<std::thread>;

class Operations
{
private:
    static std::mutex mt;
    static DataContainer m_data;
    static ThreadContainer m_threads;
public:
    Operations() = delete;
    Operations(const Operations&) = delete;
    Operations(Operations&&) = delete;
    Operations& operator=(const Operations&) = delete;
    Operations& operator=(Operations&&) = delete;
    ~Operations() = default;

    static void CreateCarsAndBikes();

    /*
        FindAverageCost : Use visit function to do this. Both Car and Bike have a m_price attribute.
        We can use their getter function to calculate total
    */

    static void FindAverageCost();
    /*
        ReturnMatchingInstance : Variant whose ID matches with the id passed
    */

    static std::optional<VrType> ReturnMatchingInstance(std::string id);

    static void Deallocate();

    static void DisplayInsuranceAmount();

    /*
        scenario 1 : id found, matches with a Car. seat count returned
        scenario 2: id found, matches with a Bike ----> nullopt
        scenario 3 : id not found : nullopt (print a message before return)
    */
    static std::optional<unsigned int>  FindSeatCountForGivenId(std::string id);

    /*
        Mapthreads : Attach a thread to a functionality
    */
    static void MapThreads();
    /*
        JoinThreads : Blocking main for respective functions executing in threads
    */
    static void JoinThreads();

};

#endif // OPERATIONS_H
