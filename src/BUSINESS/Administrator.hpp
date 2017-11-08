// Uber alles vezerloegyseg
// Main business logic
// listazza a projecteket
// interface-t nyujt a presentation layernek

//<>ProjectOrganozer
#ifndef ADMIN_HPP
#define ADMIN_HPP

#include "Deadline.hpp"
#include <vector>
#include <algorithm>
#include "../DAO/DAO.hpp"
class Administrator {
    Administrator ();

    const DAOFactory      m_dao_factory = DAOFactory ();
    const DAOEmployee&    m_dao_empl    = *m_dao_factory.getDAO<DAOEmployee> ();
    const DAOTask&        m_dao_task    = *m_dao_factory.getDAO<DAOTask>     ();
    const DAOProject&     m_dao_project = *m_dao_factory.getDAO<DAOProject>  ();
    
    std::vector<Project>  m_projects = m_dao_project.getAll ();
    std::vector<Task>     m_tasks    = m_dao_task.getAll ();
    std::vector<Employee> m_empls    = m_dao_empl.getAll ();
public:
    static Administrator& make_admin ();
    std::vector<Project>  list_projects  () const {return m_projects;}
    std::vector<Task>     list_tasks     () const {return m_tasks;   }
    std::vector<Employee> list_employees () const {return m_empls;   }
    std::vector<Deadline> list_deadlines () const ;

    void drop_project  (const std::string& p_name);
    void drop_task     (const std::string& p_name);
    void drop_employee (const std::string& p_name);

    void make_project  (
        const std::string& p_name,
        const std::string& p_desc
    );
    void make_task     (
        const std::string& p_name, 
        const std::string& p_type,  
        const std::string& p_priority, 
        const std::string& p_deadline, 
        const std::string& p_project, 
        const std::string& p_desc);
    void make_employee (
        const std::string& name,
        const std::string& address, 
        const std::string& email,
        const std::string& phone);
    
    Administrator (Administrator const&)           = delete;
    Administrator& operator=(Administrator const&) = delete;
    
    Administrator (Administrator&&)           = default;
    Administrator& operator=(Administrator&&) = default;
};

Administrator::Administrator ()
{
    
}

Administrator& Administrator::make_admin ()
{
    static Administrator m_instance = Administrator ();
    return m_instance;
}

void Administrator::drop_project  (const std::string& p_name)
{
     for (auto i: m_projects)
        if (i.get_name () == p_name)
            m_dao_project.deleteFromDB (&i);
    m_projects.erase( std::remove_if( m_projects.begin(), m_projects.end(), [&](auto& i){return i.get_name () == p_name;} ), m_projects.end() );
}

void Administrator::drop_task     (const std::string& p_name)
{
    
     for (auto i: m_tasks)
        if (i.get_name () == p_name)
            m_dao_task.deleteFromDB (&i);
    m_tasks.erase( std::remove_if( m_tasks.begin(), m_tasks.end(), [&](auto& i){return i.get_name () == p_name;} ), m_tasks.end() );
}

void Administrator::drop_employee (const std::string& p_name)
{
    
    for (auto i: m_empls)
        if (i.get_name () == p_name)
            m_dao_empl.deleteFromDB (&i);
    m_empls.erase( std::remove_if( m_empls.begin(), m_empls.end(), [&](auto& i){return i.get_name () == p_name;} ), m_empls.end() );
}

void Administrator::make_project  (
    const std::string& p_name,
    const std::string& p_desc
)
{
    Project project = Project (p_name, p_desc);
    m_dao_project.addToDB (&project);
    m_projects.push_back (project);
}
void Administrator::make_task     (
    const std::string& p_name, 
    const std::string& p_type,  
    const std::string& p_priority, 
    const std::string& p_deadline, 
    const std::string& p_project, 
    const std::string& p_desc)
{
    Task task = Task (p_name, p_type, p_priority, p_deadline, p_project, p_desc);
    m_dao_task.addToDB (&task);
    m_tasks.push_back (task);
}
void Administrator::make_employee (
    const std::string& p_name,
    const std::string& p_address, 
    const std::string& p_email,
    const std::string& p_phone)
{
    Employee empl = Employee (p_name, p_address, p_email, p_phone);
    m_dao_empl.addToDB (&empl);
    m_empls.push_back (empl);
}

std::vector<Deadline> Administrator::list_deadlines () const {
    std::vector<Deadline> deadlines;
    for (const auto& task: m_tasks)
        deadlines.push_back (task.get_deadline ());
    return deadlines;
}
#endif