//RAII : Resource Acqusition Is Initialization


/*

    Resources:
        1)memory
        2)open files
        3)NEtwork connection


*/

#include <iostream>

class ABC
{
private:
    /* data */
    int m_id{0};
    float* m_valueptr{nullptr};
public:
    ABC(/* args */)=default;
    ABC(const ABC&)=delete;
    ABC(int id,float* ptr):m_id{id},m_valueptr{ptr}{}
    ABC(ABC&&)=delete;
    ABC& operator=(const ABC&)=delete;
    ABC operator=(ABC&&)=delete;
    ~ABC() {
        delete m_valueptr;//memory leakage prevented
    }
};


template <typename T>
class Wrapper
{
private:
    T * m_ptr;

public:
    Wrapper(T* ptr):m_ptr{ptr}{}
    ~Wrapper(){
        delete m_ptr;
    }
};
void magic(){
    Wrapper<ABC> wr_obj{(new ABC(102,new float(300.0f)))};
}

int main(){
   // ABC obj{101,new float(200.0f)};
    //ABC *obj2{new ABC(102,new float(300.0f))};
    magic();
}

/*
1) main calls magic
2)in magic function we create wr_obj[stack memory]
3)wr_obj stores the address of the heap allocated object
4)wr_obj goes out of scopewr_obj goes out of scope at the end of magic function 
 since wr_obj is a
5)wrapper  */

/*

memory --->box [mwmory will be shared][box is called shared pointer];
memory ---->box[memory wii never be shared][box is called unique pointer]
memory ----->box[memory will "stalked"][box is called weak_ptr]
function/callables -->box [box is a called function wrapper]
references--->box [box is called reference pointer]
semaphores(mutex)-->box [box is called a) mutex b)lock_gaurd 3)unique_lock-------]


*/