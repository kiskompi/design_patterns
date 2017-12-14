#include "Task.hpp"
Task::Task (const std::string& p_name, 
          const std::string& p_type,  
          const std::string& p_priority, 
          const std::string& p_deadline, 
          const std::string& p_desc,
          const std::string& p_project):
        m_name     (p_name), 
        m_type     (p_type), 
        m_priority (std::stoi(p_priority)), 
        m_deadline (p_deadline), 
        m_desc     (p_desc),
        m_project  (p_project){}

 std::string Task::get_name      () const {return m_name;}
 std::string Task::get_type      () const {return m_type;}
 std::string Task::get_desc      () const {return m_desc;}
 std::string Task::get_project   () const {return m_project;}
 Employee    Task::get_employee  () const {return *m_empl;}
 std::string Task::get_deadline  () const {return m_deadline.to_string();}

 std::string Task::set_name      (const std::string& param) {m_name = param;}
 std::string Task::set_type      (const std::string& param) {m_type = param;}
 std::string Task::set_Desc      (const std::string& param) {m_desc = param;}
 std::string Task::set_project   (const std::string& param) {m_project = param;}
 std::string Task::set_deadline  (const Date&        param) {m_deadline = Deadline (param);}

std::string Task::to_string () const {
    return "'" + m_name + "','" + m_type + "', '" + std::to_string(m_priority) + "', '" + m_deadline.to_string() + "', '" + m_desc + "', '" + m_project + "','" + m_empl->get_name () + "'" ;
}

// assign_to (employee) -- puts it into TASKS_EMPOYEES table with given employee
// should be in BUSINESS layer!
void Task::assign_to(const Employee& p_emp) {
    // calls query from dao layer to insert entry to TASKS_EMPLOYEES
    // somehow represents it in business or transfer layer
    // "INSERT INTO TASKS_EMPLOYEES";
    m_empl = std::make_shared<Employee> (p_emp);
}

bool Task::operator==(const Task& other) const 
{
    return 
    (
        m_name     == other.m_name &&
        m_type     == other.m_type &&
        m_desc     == other.m_desc &&
        m_project  == other.m_project &&
        m_deadline == other.m_deadline &&
        m_empl     == other.m_empl
    );
}

bool Task::operator!=(const Task& other) const 
{
    return 
    (
        m_name     != other.m_name &&
        m_type     != other.m_type &&
        m_desc     != other.m_desc &&
        m_project  != other.m_project &&
        m_deadline != other.m_deadline &&
        m_empl     != other.m_empl
    );
}

Task& Task::operator=(const Task& other) 
{
    m_name     = other.m_name;
    m_type     = other.m_type;
    m_desc     = other.m_desc;
    m_project  = other.m_project;
    m_deadline = other.m_deadline;
    m_empl     = other.m_empl;
    return *this;
}


