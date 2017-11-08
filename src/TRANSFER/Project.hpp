#ifndef PROJECT_HPP
#include <string>
#include "Object.hpp"

class DAOProject;
class Project: public TransferObject
{
public:
    Project ();
    Project (Project  &&)      = default;
    Project (const Project  &) = default;
    Project (const std::string& name, const std::string& desc):
        m_name(name),
        m_desc(desc){}
    ~Project ();
    
    Project  &operator= (Project &&)      = default;
    Project  &operator= (const Project &) = default;

    std::string to_string  () const ;
    std::string get_name   () const {return m_name;}
    std::string get_desc   () const {return m_desc;}
    friend class DAOProject;
private:
    std::string m_name;
    std::string m_desc;
};

Project ::Project ()
{
}

Project ::~Project ()
{
}

std::string Project::to_string () const 
{
    return "'" + m_name + "', '" + m_desc +"'";
}
#endif // !PROJECT_HPP