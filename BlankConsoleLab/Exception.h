#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <ostream>
#include <string>

using std::ostream;
using std::string;

class Exception : virtual public std::exception
{
    string msg;
public:

    Exception();
    Exception(const string msg);
    Exception(const Exception& copy);
    ~Exception();

    //getters & setters
    const string getMessage();
    void setMessage(string msg);

    //operator overloads
    Exception& operator = (const Exception& exception);
    friend std::ostream& operator << (std::ostream& os, const Exception& exception);

};

Exception::Exception()
{
    msg = "Default Error";      //set default msg
}

Exception::Exception(const string newmsg)
{
    msg = newmsg;   //set msg to newmsg
}

Exception::Exception(const Exception& copy)
{
    msg = copy.msg; //set msg to copy's msg
}

Exception::~Exception()
{
    //default destructor
}

//Getters & Setters------------------------------------------------
//-----------------------------------------------------------------

const string Exception::getMessage()
{
    return msg;     //return msg
}

void Exception::setMessage(string newmsg)
{
    msg = newmsg;   //set msg to new message
}

//Operator Overloads-----------------------------------------------------
//-----------------------------------------------------------------------

Exception& Exception::operator = (const Exception& rhs)
{
    if (this != &rhs)
        msg = rhs.msg;  //if both exceptions aren't the same, set this msg to rhs' msg

    return *this;
}

ostream& operator << (ostream& os, const Exception& exception)
{
    return os << exception.msg;     //place message into outstream and return it
}
#endif