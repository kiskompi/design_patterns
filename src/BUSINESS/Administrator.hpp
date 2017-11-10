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
    std::vector<T> list (std::string);


    template<typename T>
    std::vector<T> drop (std::string);

    template<typename T>
    std::vector<T> make (std::vector<std::string>);

    Administrator (Administrator const&)           = delete;
    Administrator& operator=(Administrator const&) = delete;
    
    Administrator (Administrator&&)           = default;
    Administrator& operator=(Administrator&&) = default;

    short assign_task  (const std::string& taskStr, const std::string& emplStr);
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
    std::vector<Task> tasks = list_tasks ();
    std::vector<Employee> empls = list_employees ();
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

    m_dao_task.create_table_tasks_employees ();
    m_dao_task.assign (*empl, *task);
    return 0;
}



template<typename T>
std::vector<T> list (std::string str) {
    m_lister.
}


template<typename T>
std::vector<T> drop (std::string str) {

}

template<typename T>
std::vector<T> make (std::vector<std::string>) {

}
#endif