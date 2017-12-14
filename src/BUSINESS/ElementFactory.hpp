#ifndef ELEMENTFACTORY_HPP
#define ELEMENTFACTORY_HPP

#include "../TRANSFER/Employee.hpp"
#include "../TRANSFER/Task.hpp"
#include "../TRANSFER/Project.hpp"

class ElementFactory
{

public:
	ElementFactory () {}

    virtual Project  make_element (std::string, std::string) const {};
    virtual Task 	 make_element (std::string, std::string, std::string, std::string, std::string, std::string) const {};
    virtual Employee make_element (std::string, std::string, std::string, std::string) const {};
};
  
#endif // ELEMENTFACTORY_HPP
