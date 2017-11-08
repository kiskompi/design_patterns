#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP
#include <string>
#include "Object.hpp"

class DAOEmployee;
class Employee : public TransferObject
{
public:
    Employee ();
    Employee (Employee  &&) = default;
    Employee (const Employee  &) = default;
    Employee (const std::string& name,const std::string& address, const std::string& email,const std::string& phone):
        m_name(name), m_address(address), m_email(email), m_phone(phone){}
    Employee  &operator=(Employee  &&) = default;
    Employee  &operator=(const Employee  &) = default;
    ~Employee ();

    std::string to_string () const {
        return "'" + m_name + "','" + m_address + "', '" + m_email + "', '" + m_phone + "'" ;
    }
    
    std::string get_name    () const {
        return m_name;
    }
    std::string get_address () const {
        return m_address;
    }
    std::string get_email   () const {
        return m_email;
    }
    std::string get_phone   () const {
        return m_phone;
    }

    friend class DAOEmployee;
private:
    std::string m_name;
    std::string m_address;
    std::string m_email;
    std::string m_phone;
};

Employee ::Employee ()
{
}

Employee ::~Employee ()
{
}
#endif // !EMPLOYEE_HPP