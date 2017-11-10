#ifndef ELEMENTFACTORY_HPP
#define ELEMENTFACTORY_HPP

#include "../LIB/Factory.hpp"
#include "../TRANSFER/Project.hpp"
#include "../TRANSFER/Task.hpp"
#include "../TRANSFER/Employee.hpp"

class ElementFactory
{

public:
	ElementFactory () {}

    TransferObject get (std::vector<std::string> v) const {
        static_assert(std::is_base_of<TransferObject, Type>::value, "Template argument is not a DAO");
        
        return new Type ();
    }

    Project make_element  (
        const std::string& p_name,
        const std::string& p_desc
    );
    Task make_element (
        const std::string& p_name, 
        const std::string& p_type,  
        const std::string& p_priority, 
        const std::string& p_deadline, 
        const std::string& p_project, 
        const std::string& p_desc);
    
    Employee make_element (
        const std::string& name,
        const std::string& address, 
        const std::string& email,
        const std::string& phone);
	
};
    

void ElementFactory::make_element  (
    const std::string& p_name,
    const std::string& p_desc
)
{
    Project project = Project (p_name, p_desc);
    m_dao_project.add (&project);
    m_projects.push_back (project);
}
void ElementFactory::make_element     (
    const std::string& p_name, 
    const std::string& p_type,  
    const std::string& p_priority, 
    const std::string& p_deadline, 
    const std::string& p_project, 
    const std::string& p_desc)
{
    Task task = Task (p_name, p_type, p_priority, p_deadline, p_project, p_desc);
    m_dao_task.add (&task);
    m_tasks.push_back (task);
}
void ElementFactory::make_element (
    const std::string& p_name,
    const std::string& p_address, 
    const std::string& p_email,
    const std::string& p_phone)
{
    Employee empl = Employee (p_name, p_address, p_email, p_phone);
    m_dao_empl.add (&empl);
    m_empls.push_back (empl);
}

#endif ELEMENTFACTORY_HPP