#ifndef ELEMDROPPER_HPP
#define ELEMDROPPER_HPP

#include <string>
#include <algorithm>

#include "../DAO/DAO.hpp"
#include "../TRANSFER/Project.hpp"
#include "../TRANSFER/Task.hpp"
#include "../TRANSFER/Employee.hpp"

class ElementDropper {
    DAOFactory m_df = DAOFactory ();
public:
    void drop_project  (const std::string& p_name);
    void drop_task     (const std::string& p_name);
    void drop_employee (const std::string& p_name);	
};

#endif
