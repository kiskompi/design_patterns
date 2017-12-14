#ifndef TASK_HPP
#define TASK_HPP

#include <string>
#include <memory>
#include "Object.hpp"
#include "../BUSINESS/Deadline.hpp"
#include "Employee.hpp"

typedef std::shared_ptr<Employee> emp_ptr;
class DAOTask;
class Task : public TransferObject
{
public:
    Task () = default;
    Task (Task&&)       = default;
    Task (const Task& ) = default;    
    Task (const std::string& p_name, 
          const std::string& p_type,  
          const std::string& p_priority, 
          const std::string& p_deadline, 
          const std::string& p_desc,
          const std::string& p_project);

    Task&  operator=(const Task&);
    bool  operator==(const Task&) const;
    bool  operator!=(const Task&) const;
    // TODO add a Project field
    virtual std::string to_string () const ;
    virtual std::string get_name      () const ;
    virtual std::string get_type      () const ;
    virtual std::string get_desc      () const ;
    virtual std::string get_project   () const ;
    virtual Employee    get_employee  () const ;
    virtual std::string get_deadline  () const ;
    
    virtual std::string set_name      (const std::string& param); 
    virtual std::string set_type      (const std::string& param); 
    virtual std::string set_Desc      (const std::string& param); 
    virtual std::string set_project   (const std::string& param); 
    virtual std::string set_deadline  (const Date&        param); 
    void                assign_to(const Employee& p_emp);

    ~Task () = default;
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
#endif // !TASK_HPP
