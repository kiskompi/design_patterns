#ifndef PROJECT_HPP
#define  PROJECT_HPP
#include <string>
#include "Object.hpp"

class DAOProject;
class Project: public TransferObject
{
public:
    Project () = default;
    Project (Project  &&)      = default;
    Project (const Project  &) = default;
    Project (const std::string& name, const std::string& desc);
    ~Project ()= default;
    
    Project  &operator= (Project &&)      = default;
    Project  &operator= (const Project &) = default;

    std::string to_string  () const ;
    std::string get_name   () const ;
    std::string get_desc   () const ;
    friend class DAOProject;
private:
    std::string m_name;
    std::string m_desc;
};

#endif // !PROJECT_HPP
