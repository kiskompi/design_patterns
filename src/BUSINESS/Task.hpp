#ifndef TASK_HPP
#include <string>
#include "Object.hpp"
#include "Date.hpp"

class DAOTask;
class Task : public Object
{
public:
    Task ();
    Task (Task  &&) = default;
    Task (const Task  &) = default;
    Task (const std::string& p_name, 
          const std::string& p_type,  
          const std::string& p_priority, 
          const std::string& p_deadline, 
          const std::string& p_desc):
        m_name     (p_name), 
        m_type     (p_type), 
        m_priority (std::stoi(p_priority)), 
        m_deadline (p_deadline), 
        m_desc     (p_desc) {}

    Task  &operator=(Task  &&) = default;
    Task  &operator=(const Task  &) = default;
    virtual std::string getPrintable ();
    virtual std::string getName(){return m_name;}
    virtual std::string getType(){return m_type;}
    virtual std::string getDesc(){return m_desc;}
    virtual std::string getDeadline(){return m_deadline.to_string();}


    ~Task ();
    friend class DAOTask;
private:
    std::string m_name;
    std::string m_type;
    std::string m_desc;
    Date m_deadline;

    unsigned short m_priority;
};

Task ::Task ()
{
}

Task ::~Task ()
{
}


std::string Task::getPrintable (){
    return "'" + m_name + "','" + m_type + "', '" + std::to_string(m_priority) + "', '" + m_deadline.to_string() + "', '" + m_desc + "'" ;
}

#endif // !TASK_HPP