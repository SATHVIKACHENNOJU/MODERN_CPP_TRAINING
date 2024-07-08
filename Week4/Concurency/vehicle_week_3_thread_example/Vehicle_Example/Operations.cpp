#include "Operations.h"

DataContainer Operations::m_data {};
ThreadContainer Operations::m_threads {};
std::mutex Operations::mt {};

void Operations::CreateCarsAndBikes()
{
    m_data.emplace_back(  new Car("c101", 9000.0f, 4)  );
    m_data.emplace_back(  new Car("c102", 8000.0f, 4)  );
    m_data.emplace_back(  new Bike("b103", 2000.0)  );
    m_data.emplace_back(  new Car("c104", 9000.0f, 4)  );
    m_data.emplace_back(  new Bike("b105", 3000.0f)  );
}

void Operations::FindAverageCost()
{
    if (m_data.empty()){
        mt.lock();
        std::cerr << "Empty data container\n";
        mt.unlock();
    }

    float total {0.0f};

    for(const VrType v : m_data) {
        std::visit( [&] (auto&& val) { total += val->price();}, v );
    }

    if(!m_data.empty()){
        mt.lock();
        std::cout << "Average cost is: " << total/m_data.size() << "\n";
        mt.unlock();
    }
}

std::optional<VrType> Operations::ReturnMatchingInstance(std::string id)
{
    if (m_data.empty()){
        mt.lock();
        std::cerr << "Empty data container\n";
        mt.unlock();
    }

    std::optional<VrType> result{std::nullopt};
    bool m_id_found {false};

    for(const VrType v : m_data) {
        std::visit( 
            [&] (auto&& val) { if(val->id() == id)  { result = v; m_id_found = true; } }, v);

        if (m_id_found) {
            break;
        }
    }

    return result;
}

void Operations::Deallocate()
{
    if (m_data.empty()){
        std::cerr << "Empty data container\n";
    }

    for(const VrType v : m_data) {
        std::visit([](auto&& val) {   delete val;  }, v);
    }
}

void Operations::DisplayInsuranceAmount()
{
    if (m_data.empty()){
        mt.lock();
        std::cerr << "Empty data container\n";
        mt.unlock();
    }

    for(const VrType v : m_data) {
        std::visit([](auto&& val) {  mt.lock();  std::cout << val->InsuranceAmount() <<"\n"; mt.unlock(); }, v);
    }
}

std::optional<unsigned int> Operations::FindSeatCountForGivenId(std::string id)
{
    if (m_data.empty()){
        mt.lock();
        std::cerr << "Empty data container\n";
        mt.unlock();
    }

    std::optional<unsigned int> result {std::nullopt};
    bool matchFound {false};
    
    for(const VrType v : m_data) {
        if (std::holds_alternative<Car*>(v)) {    
            Car* temp = std::get<0>(v);

            if (temp->id() == id) {
                matchFound = true;
                result = temp->seatCount();
            }
        }
    }

    if (!matchFound && !m_data.empty()) {
        mt.lock();
        std::cerr << "Id was not found\n";
        mt.unlock();
    }

    return result;

}

void Operations::MapThreads()
{
    m_threads.emplace_back(   Operations::FindAverageCost        );
    m_threads.emplace_back(   Operations::DisplayInsuranceAmount        );


}

void Operations::JoinThreads()
{
    for(std::thread& th : m_threads) {
        if (th.joinable()) {
            th.join();
        }
    }
}
