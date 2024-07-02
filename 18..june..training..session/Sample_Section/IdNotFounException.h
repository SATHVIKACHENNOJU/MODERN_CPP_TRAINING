#ifndef IDNOTFOUNEXCEPTION_H
#define IDNOTFOUNEXCEPTION_H
#include <iostream>
class IdNotFounException : public std::exception
{
private:
    std::string msg;
public:
#include<exception>
    IdNotFounException(std::string s){
        this->msg=s;

    }
     virtual const char*
    what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW{
        return msg.c_str();
    }

    ~IdNotFounException(){}
};

#endif // IDNOTFOUNEXCEPTION_H
