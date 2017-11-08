#ifndef TRANSFEROBJECT_HPP
#define TRANSFEROBJECT_HPP
#include <string>

class TransferObject
{
public:
    // Returns the fields of the TransferObject in an std::string, separated by commas
    virtual std::string to_string (){return std::string();}
    virtual std::string get_ame   (){return std::string();}
    virtual ~TransferObject(){}

private:
    
};

#endif