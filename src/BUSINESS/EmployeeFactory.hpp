#ifndef EMPLOYEEFACTORY_HPP
#define EMPLOYEEFACTORY_HPP

#include "../TRANSFER/Employee.hpp"
#include "../DAO/DAO.hpp"

class EmployeeFactory: public ElementFactory
{
    DAOEmployee m_dao_empl = DAOFactory ().get<DAOEmployee> ();

public:
	EmployeeFactory () {}

    virtual Employee make_element (   
            const std::string& p_name,
            const std::string& p_address, 
            const std::string& p_email,
            const std::string& p_phone) const {
        Employee empl = Employee (p_name, p_address, p_email, p_phone);
        m_dao_empl.add (&empl);
        return empl;
    }

};
    


#endif //EMPLOYEEFACTORY_HPP
