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
    ElementLister  m_lister   = ElementLister  ();  // strategy


public:
    static Administrator& make_admin   ();
    
    template<typename T>
    std::vector<T> list (const std::string& str = "");
    
    template<typename T>
    T make_element (std::vector<std::string>);

    Administrator (Administrator const&)           = delete;
    Administrator& operator=(Administrator const&) = delete;
    
    Administrator (Administrator&&)           = default;
    Administrator& operator=(Administrator&&) = default;

    short assign_task  (const std::string& taskStr, const std::string& emplStr);
    short switch_tasks (const std::string& taskStr, const std::string& emplStr);
};


#endif
