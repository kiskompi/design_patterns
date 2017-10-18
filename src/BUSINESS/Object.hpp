#ifndef OBJECT_HPP
#define OBJECT_HPP
#include <string>

class Object
{
public:
    // Returns the fields of the Object in an std::string, separated by commas
    virtual std::string getPrintable (){return std::string();}
    virtual std::string getName(){return std::string();}
    virtual ~Object(){}

private:
    
};

#endif