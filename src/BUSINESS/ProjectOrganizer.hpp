// Composite
// ProjectOrganizer
// * benne van a Project
// * egy tasklist (a projecté)
// * az employeek (akik részt vesznek, a taskokból kilistázva)

// TaskHandler

#ifndef PROJECTORG_HPP
#define PROJECTORG_HPP

#include "../LIB/dynamic_array.hpp"
#include "../TRANSFER/Project.hpp"
#include "../TRANSFER/Task.hpp"
#include "../TRANSFER/Employee.hpp"

class ProjectOrganizer {
    Project*               m_project;
    std::vector<Task*>     m_tasks;
    std::vector<Employee*> m_emps;

public:
    ProjectOrganizer  ();
    ~ProjectOrganizer ();

    // ListTasks
    
    // ListEmpls
    // Name
    // TaskFactory

    // ### Mediator
    // Task exchange between Employees
};

#endif
