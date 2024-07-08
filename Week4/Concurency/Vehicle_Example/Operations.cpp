#include "Operations.h"

void Operations::CreateCarsAndBikes()
{
    // m_data.emplace_back(new Car("DEF",1000000.0f,6),new Bike("ABC",10000.0f));
    // m_data.emplace_back(new Car("GHI",500000.0f,9),new Bike("MNO",40000.0f));
    // m_data.emplace_back(new Car("PQR",700000.0f,10),new Bike("STU",20000.0f));

    m_data.emplace_back(new Car("DEF",1000000.0f,6));
    m_data.emplace_back(new Car("GHI",500000.0f,9));
    m_data.emplace_back(new Bike("ABC",10000.0f));
    m_data.emplace_back(new Bike("MNO",40000.0f));
    m_data.emplace_back(new Car("PQR",700000.0f,10));
    m_data.emplace_back(new Bike("STU",20000.0f));
    //m_data.emplace_back(nullptr);

}

void Operations::FindAverageCost()
{
   if(m_data.empty()){
    mt.lock();
    std::cerr<<"Empty data Container\n";
    mt.unlock();
   } 
   float total{0.0f};

   for(const VrType v : m_data)
   {
    std::visit([&](auto&& val){total +=val->price();},v);
   }
   if(m_data.empty()){
    std::cout<<"Average cost is:"<<total/m_data.size()<<"\n";
   }
}

std::optional<VrType> Operations::ReturnMatchingInstanc(std::string id)
{
    if(m_data.empty()){
        mt.lock();
    std::cerr<<"Empty data Container\n";
    mt.unlock();
   } 
   std::optional<VrType> result{std::nullopt};

   for(const VrType v : m_data){
    std::visit([&](auto &&val){if(val->id()==id){result =v;}}, v);
   }
}

void Operations::Deallocate()
{
    if(m_data.empty()){
        mt.lock();
    std::cerr<<"Empty data Container\n";
    mt.unlock();
   } 

}

void Operations::DisplayInsuranceAmount()
{
    if(m_data.empty()){
        mt.lock();
        std::cerr<<"Empty data container\n";
        mt.unlock();
    }
    for(const VrType v : m_data){
        std::visit([&](auto &&val){ std::cout<<val->InsuranceAmount()<<"\n";},v);
    }
}

std::optional<unsigned int> Operations::FindCOuntForGivenId(std::string id)
{
    if(m_data.empty()){
        std::cerr<<"Empty data container\n";
    }

    std::optional<unsigned int> result {std::nullopt};
    bool matchFound {false};

    for(const )
    
}

void Operations::MapThreads()
{
    m_threads.emplace_back(Operations::FindAverageCost);
    m_threads.emplace_back(Operations::DisplayInsuranceAmount);
}

void Operations::JoinThreads()
{
    for(std::thread& th : m_threads){
        {
            if(th.joinable())
            {
                th.join();
            }

        }
    }
}
