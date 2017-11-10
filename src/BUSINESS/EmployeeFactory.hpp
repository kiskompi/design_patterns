#ifndef ELEMENTFACTORY_HPP
#define ELEMENTFACTORY_HPP

#include "../TRANSFER/Project.hpp"
#include "../TRANSFER/Task.hpp"
#include "../TRANSFER/Employee.hpp"

class EmployeeFactory: public ElementFactory
{
    DAOFactory<Employee> m_dao_empl = DAOFactory<Employee> ();

public:
	EmployeeFactory () {}

    TransferObject get (   
            const std::string& p_name,
            const std::string& p_address, 
            const std::string& p_email,
            const std::string& p_phone) const {
        Employee empl = Employee (p_name, p_address, p_email, p_phone);
        m_dao_empl.add (&empl);
        m_empls.push_back (empl);
        return new Type ();
    }

	
};
    


#endif ELEMENTFACTORY_HPP