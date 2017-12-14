#include "Employee.hpp"


Employee::Employee (const std::string& name,const std::string& address, const std::string& email,const std::string& phone):
        m_name(name), m_address(address), m_email(email), m_phone(phone){}

std::string Employee::to_string () const {
	return "'" + m_name + "','" + m_address + "', '" + m_email + "', '" + m_phone + "'" ;
}

std::string Employee::get_name    () const {
	return m_name;
}
std::string Employee::get_address () const {
	return m_address;
}
std::string Employee::get_email   () const {
	return m_email;
}
std::string Employee::get_phone   () const {
	return m_phone;
}


