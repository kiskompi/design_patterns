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

static std::string str_tolower(std::string s) {
    std::transform(s.begin(), s.end(), s.begin(), 
        [](unsigned char c){ return std::tolower(c); } // correct
    );
    return s;
}

CMD CommandAdapter::lookup_command (std::string strCommand) const
{
    std::string lowercase = str_tolower (strCommand);
    if (lowercase == "list")
        return CMD::LIST;
    if (lowercase ==  "make")
        return CMD::MAKE;
    if (lowercase ==  "drop")
        return CMD::DROP;
    if (lowercase ==  "switch")
        return CMD::SWITCH;
    if (lowercase ==  "assign")
        return CMD::ASSIGN;
    if (lowercase ==  "quit")
        return CMD::QUIT;
    if (lowercase ==  "help")
        return CMD::HELP;
    else
        std::cout<<"Command not found!\n";
    return CMD::HELP;
}

TARGET CommandAdapter::lookup_target (std::string strTarget) const
{
    std::string lowercase = str_tolower (strTarget);
    
    if (lowercase == "project")
        return TARGET::PROJECTS;
    if (lowercase == "task")
        return TARGET::TASKS;
    if (lowercase == "employee")
        return TARGET::EMPLS;
    if (lowercase == "deadline")
        return TARGET::DEADLINES;
    else
        std::cout<<"Target not found!\n";
    return TARGET::NOTFOUND;
}

void CommandAdapter::execute (const Command cmd) const {

}

static std::vector<std::string> split(const std::string &txt)
{
    std::vector<std::string> tokens;
    std::string buf;
    std::stringstream ss(txt);
    while (ss >> buf)
        tokens.push_back(buf);
    return tokens;
}

void CommandAdapter::execute_dummy (const std::string cmd) {
    // VERY DUMMY
    std::vector<std::string> v = split( cmd );
    if (v.empty ())
        return;
    switch (lookup_command(v[0]))
    {
        case CMD::LIST:{
            switch (lookup_target(v[1]))
            {
                case TARGET::PROJECTS:{
                    auto vec = m_admin.list<DAOProject>  ();
                    for (auto i: vec)
                        std::cout<<i.to_string ()<<"\n";
                    break;
                }
                case TARGET::TASKS:{
                    auto vec = m_admin.list<DAOTask>  ();
                    for (auto i: vec)
                        std::cout<<i.to_string ()<<"\n";
                    break;
                }
                case TARGET::EMPLS:{
                    auto vec = m_admin.list<DAOEmployee> ();
                    for (auto i: vec)
                        std::cout<<i.to_string ()<<"\n";
                    break;
                }
                case TARGET::DEADLINES:{
                    auto vec = m_admin.list<DAODeadline>  ();
                    for (auto i: vec)
                        std::cout<<i.to_string ()<<"\n";
                    break;
                }
                default:
                    std::cerr<<"Bad argument!\n";
            }
        }
        break;
        case CMD::DROP:{
            switch (lookup_target(v[1]))
            {
                case TARGET::PROJECTS:
                    m_admin.drop<Project> (v[2]);
                    break;
                case TARGET::TASKS:
                    m_admin.drop<Task> (v[2]);
                    break;
                case TARGET::EMPLS:
                    m_admin.drop<Employee> (v[2]);
                    break;
                default:
                    std::cerr<<"Bad argument!\n";
            }
        }
        break;
        case CMD::MAKE:{
            switch (lookup_target(v[1]))
            {
                case TARGET::PROJECTS: {
                    if (v.size () < 4){
                        std::cerr<<"Not enough argument!\n";
                        break;
                    }
                    DAOProject dp = m_dao_factory.get<DAOProject> ();
                    Project elem = m_element_factory.get_project (v[2], v[3]);
                    dp.add (&elem);
                    break;
                }
                case TARGET::TASKS:{
                    if (v.size () < 8){
                        std::cerr<<"Not enough argument!\n";
                        break;
                    }
                    Task task = m_element_factory.get_task (v[2], v[3], v[4], v[5], v[6], v[7]);
                    break;
                }
                case TARGET::EMPLS:{
                    if (v.size () < 6){
                        std::cerr<<"Not enough argument!\n";
                        break;
                    }
                    Employee empl = m_element_factory.get_employee (v[2], v[3], v[4], v[5]);
                    break;
                }
                default:
                    std::cerr<<"Bad argument!\n";
            }
        }
        break;
        case CMD::SWITCH: {
            if (lookup_target(v[1]) == TARGET::TASKS){
                short err = m_admin.switch_tasks (v[2], v[3]);
                if (err != 0)
                    std::cerr<<"No such task!\n ";
            }
        }
        break;
        case CMD::ASSIGN: {
            if (lookup_target(v[1]) == TARGET::TASKS){
                short err = m_admin.assign_task (v[2], v[3]);
                if (err != 0)
                    std::cerr<<"No such task or employee!\n ";
            }
        }
        break;
        case CMD::HELP:
            std::cout<<"LIST [TARGET]           - lists all from [target]\n"
                     <<"DROP [TARGET] [NAME]    - deletes all of [target] with name [name]\n"
                     <<"MAKE [TARGET] [ARGS...] - creates [target] with specified parameters\n"
                     <<"HELP                    - displays this screen\n"
                     <<"QUIT                    - quits program\n"<<std::endl;
            break;
        case CMD::QUIT:
            exit(0);
        default:
            std::cout<<"Bad command. For help, write: HELP\n";
    }
    std::cout<<std::flush;
}

void CommandAdapter::ask (std::string& str) const {
    std::cout<<"\nCMD:: ";
    std::getline (std::cin,str);
    std::cout<<std::endl;
}
#endif // COMMANDADAPTER_HPP
