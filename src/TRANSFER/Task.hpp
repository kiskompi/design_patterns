#ifndef TASK_HPP
#include <string>
#include <memory>
#include "Object.hpp"
#include "../BUSINESS/Deadline.hpp"
#include "Employee.hpp"
#include "../DAO/DAUtils.cpp"

typedef std::shared_ptr<Employee> emp_ptr;
class DAOTask;
class Task : public TransferObject
{
public:
    Task ();
    Task (Task&&)       = default;
    Task (const Task& ) = default;    
    Task (const std::string& p_name, 
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

    Task&  operator=(const Task&);
    bool  operator==(const Task&) const;
    bool  operator!=(const Task&) const;
    // TODO add a Project field
    virtual std::string to_string () const ;
    virtual std::string get_name      () const {return m_name;}
    virtual std::string get_type      () const {return m_type;}
    virtual std::string get_desc      () const {return m_desc;}
    virtual std::string get_project   () const {return m_project;}
    virtual Employee    get_employee  () const {return *m_empl;}
    virtual std::string get_deadline  () const {return m_deadline.to_string();}
    
    virtual std::string set_name      (const std::string& param) {m_name = param;}
    virtual std::string set_type      (const std::string& param) {m_type = param;}
    virtual std::string set_Desc      (const std::string& param) {m_desc = param;}
    virtual std::string set_project   (const std::string& param) {m_project = param;}
    virtual std::string set_deadline  (const Date&        param) {m_deadline = Deadline (param);}
    void                assign_to(const Employee& p_emp);

    ~Task ();
    friend class DAOTask;
private:
    std::string m_name     = "";
    std::string m_type     = "";
    std::string m_desc     = "";
    std::string m_project  = "";
    Deadline    m_deadline = Deadline ();
    emp_ptr     m_empl     = std::make_shared<Employee> (Employee ());

    unsigned short m_priority = 0;
};

Task ::Task ()
{
}

Task ::~Task ()
{
}

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

#endif // !TASK_HPP