#include "Project.hpp"
std::string Project::to_string () const 
{
    return "'" + m_name + "', '" + m_desc +"'";
}

Project::Project (const std::string& name, const std::string& desc):
	m_name(name),
	m_desc(desc){}
std::string Project::get_name   () const {return m_name;}
std::string Project::get_desc   () const {return m_desc;}
 
