// Uber alles vezerloegyseg
// Main business logic
// listazza a projecteket
// interface-t nyujt a presentation layernek

//<>ProjectOrganozer
#ifndef ADMIN_HPP
#define ADMIN_HPP

#include <vector>
#include <algorithm>

#include "../DAO/DAO.hpp"
#include "Deadline.hpp"
#include "ElementFactory.hpp"
#include "TaskSwitcher.hpp"
#include "ElementDropper.hpp"
#include "TaskLister.hpp"
#include "EmployeeLister.hpp"

class Administrator {
    Administrator ();

    const DAOFactory      m_dao_factory = DAOFactory ();
    
    ElementFactory m_factory  = ElementFactory ();  // factory
    TaskSwitcher   m_switcher = TaskSwitcher   ();  // mediator
    ElementDropper m_dropper  = ElementDropper ();  // strategy
    ElementLister  m_lister   = ElementLister  ();  // strategy


public:
    static Administrator& make_admin   ();
    
    template<typename T>
    std::vector<T> list (const std::string& str = "");
    
    template<typename T>
    std::vector<T> drop (std::string);

    template<typename T>
    T make_element (std::vector<std::string>);

    Administrator (Administrator const&)           = delete;
    Administrator& operator=(Administrator const&) = delete;
    
    Administrator (Administrator&&)           = default;
    Administrator& operator=(Administrator&&) = default;

    short assign_task  (const std::string& taskStr, const std::string& emplStr);
    short switch_tasks (const std::string& taskStr, const std::string& emplStr);
};

Administrator::Administrator ()
{
    
}

Administrator& Administrator::make_admin ()
{
    static Administrator m_instance = Administrator ();
    return m_instance;
}

short Administrator::assign_task (const std::string& taskStr, const std::string& emplStr) {
	m_lister = TaskLister ();
    std::vector<Task> 	  tasks = m_lister.list ();
	m_lister = EmployeeLister ();
    std::vector<Employee> empls = m_lister.list ();
    Task*     task = nullptr;
    Employee* empl = nullptr;

    for (auto& i: tasks) {
        if (i.get_name() == taskStr){
            task = &i;
            break;
        }
    }
    for (auto& i: empls) {
        if (i.get_name() == emplStr){
            empl = &i;
            break;
        }
    }
    if (task == nullptr || empl == nullptr)
        return -1;

    DAOTask dt = DAOTask();
    dt.create_table_tasks_employees ();
    dt.assign (*empl, *task);
    return 0;
}

template<typename T>
std::vector<T> Administrator::list (const std::string& str) {
    return m_lister.list<T>(std::move(str));
}


template<typename T>
std::vector<T> Administrator::drop (std::string str) {

}

template<typename T>
T Administrator::make_element (std::vector<std::string> vec) {
	return T(); 
}
#endif
