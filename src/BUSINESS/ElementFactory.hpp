#ifndef ELEMENTFACTORY_HPP
#define ELEMENTFACTORY_HPP

#include "../TRANSFER/Employee.hpp"
#include "../TRANSFER/Task.hpp"
#include "../TRANSFER/Project.hpp"

class ElementFactory
{

public:
	ElementFactory () {}

    virtual Project  get_project  (std::string, std::string) const;
    virtual Task 	 get_task     (std::string, std::string, std::string, std::string, std::string, std::string) const;
    virtual Employee get_employee (std::string, std::string, std::string, std::string) const;
};
  
#endif // ELEMENTFACTORY_HPP
