#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP
#include <string>
#include "Object.hpp"

class DAOEmployee;
class Employee : public TransferObject
{
public:
    Employee () = default;
    Employee (Employee  &&) = default;
    Employee (const Employee  &) = default;
    Employee (
		const std::string& name,
		const std::string& address, 
		const std::string& email,
		const std::string& phone);
    Employee  &operator=(Employee  &&) = default;
    Employee  &operator=(const Employee  &) = default;
    ~Employee () = default;

    std::string to_string () const ;    
    std::string get_name    () const ;
	std::string get_address () const ;
    std::string get_email   () const ;
    std::string get_phone   () const ;

    friend class DAOEmployee;
private:
    std::string m_name;
    std::string m_address;
    std::string m_email;
    std::string m_phone;
};

#endif // !EMPLOYEE_HPP
