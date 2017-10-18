#ifndef PROJECT_HPP
#include <string>
#include "Object.hpp"
class DAOProject;
class Project: public Object
{
public:
    Project ();
    Project (Project  &&)      = default;
    Project (const Project  &) = default;
    Project (const std::string& name, const std::string& desc):
        m_name(name), m_desc(desc){}
    Project  &operator=(Project &&)      = default;
    Project  &operator=(const Project &) = default;
    ~Project ();
    std::string getPrintable ();
    std::string getName      (){return m_name;}
    std::string getDesc      (){return m_desc;}
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

std::string Project::getPrintable()
{
    return "'" + m_name + "', '" + m_desc +"'";
}
#endif // !PROJECT_HPP