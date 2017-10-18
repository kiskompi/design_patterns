#ifndef EMPLOYEE_HPP
#include <string>
#include "Object.hpp"
#include "Object.hpp"
class DAOEmployee;
class Employee : public Object
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

    std::string getPrintable (){
        return "'" + m_name + "','" + m_address + "', '" + m_email + "', '" + m_phone + "'" ;
    }
    
    std::string getName (){
        return m_name;
    }
    std::string getAddress (){
        return m_address;
    }
    std::string getEmail (){
        return m_email;
    }
    std::string getPhone (){
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