#ifndef COMMANDADAPTER_HPP
#define COMMANDADAPTER_HPP

#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <stdlib.h>
#include "../BUSINESS/Administrator.hpp"
#include "../BUSINESS/EmployeeFactory.hpp"
#include "../BUSINESS/TaskFactory.hpp"
#include "../BUSINESS/ProjectFactory.hpp"

enum class CMD {
    LIST,
    MAKE,
    DROP,
    SWITCH,
    ASSIGN,
    HELP,
    QUIT
};

enum class TARGET {
    PROJECTS,
    TASKS,
    EMPLS,
    DEADLINES,
    NOTFOUND
};

struct Command {
    CMD    command;
    TARGET target;
};

class CommandAdapter {
    Administrator&  m_admin           = Administrator::make_admin();
    ElementFactory  m_element_factory = ElementFactory ();
    DAOFactory      m_dao_factory     = DAOFactory ();

    CMD         lookup_command (const std::string command) const;
    TARGET      lookup_target  (const std::string target)  const;
    void        execute        (const Command cmd) const;
public:
    
    CommandAdapter () {}
    void execute_dummy (const std::string);
    void ask           (std::string& str) const;
};
#endif // COMMANDADAPTER_HPP
