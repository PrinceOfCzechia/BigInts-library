#ifndef CHARRAYEXCPT_H
#define CHARRAYEXCPT_H

#include <exception>
#include <string>

class CharrayException : public std::exception
{
    std::string message;
public:
    CharrayException(std::string msg): message(msg){}
    virtual const char* what() const noexcept
    {
        return message.c_str();
    }
};

#endif // CHARRAYEXCPT_H
