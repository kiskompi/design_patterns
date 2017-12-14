#include "CommandAdapter.hpp"

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
                    auto vec = ElementLister().list_projects ();
                    for (auto i: vec)
                        std::cout<<i.to_string ()<<"\n";
                    break;
                }
                case TARGET::TASKS:{
                    auto vec = ElementLister().list_tasks ();
                    for (auto i: vec)
                        std::cout<<i.to_string ()<<"\n";
                    break;
                }
                case TARGET::EMPLS:{
                    auto vec = ElementLister().list_employees ();
                    for (auto i: vec)
                        std::cout<<i.to_string ()<<"\n";
                    break;
                }
                case TARGET::DEADLINES:{
                    auto vec = ElementLister().list_deadlines();
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
					ElementDropper ().drop_project (v[2]);
                    break;
                case TARGET::TASKS:
					ElementDropper ().drop_task(v[2]);
                    break;
                case TARGET::EMPLS:
					ElementDropper ().drop_employee (v[2]);
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
					m_element_factory =  ProjectFactory ();
                    Project elem = m_element_factory.make_element (v[2], v[3]);
                    dp.add (&elem);
                    break;
                }
                case TARGET::TASKS:{
                    if (v.size () < 8){
                        std::cerr<<"Not enough argument!\n";
                        break;
                    }
                    DAOTask dp = m_dao_factory.get<DAOTask> ();
					m_element_factory = TaskFactory ();
                    Task task = m_element_factory.make_element (v[2], v[3], v[4], v[5], v[6], v[7]);
                    break;
                }
                case TARGET::EMPLS:{
                    if (v.size () < 6){
                        std::cerr<<"Not enough argument!\n";
                        break;
                    }
					DAOEmployee de = m_dao_factory.get<DAOEmployee> ();
					m_element_factory = EmployeeFactory ();
                    Employee empl = m_element_factory.make_element (v[2], v[3], v[4], v[5]);
                    break;
                }
                default:
                    std::cerr<<"Bad argument!\n";
            }
        }
        break;
        case CMD::SWITCH: {
            if (lookup_target(v[1]) == TARGET::TASKS){
                short err = TaskSwitcher().switch_tasks (v[2], v[3]);
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

