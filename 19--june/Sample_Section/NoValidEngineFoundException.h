#ifndef NOVALIDENGINEFOUNDEXCEPTION_H
#define NOVALIDENGINEFOUNDEXCEPTION_H
#include<iostream>
class NoValidEngineFoundException : public std::exception
{
private:
    std::string _msg;
public:
    NoValidEngineFoundException(std::string msg):_msg{msg} {}

     virtual const char*
    what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW{
        return _msg.c_str();
   }

    ~NoValidEngineFoundException()=default;
};

#endif // NOVALIDENGINEFOUNDEXCEPTION_H
