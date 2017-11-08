#ifdef COMMANDADAPTER_HPP
#define COMMANDADAPTER_HPP

#include <string>

enum class CMD {
    LIST;
    CREATE;
    DROP;
    HELP;
    QUIT;
};

enum class TARGET {
    PROJECTS;
    TASKS;
    EMPLS;
    NOTFOUND;
};


class CommandAdapter {
    Administrator                        m_admin    = Administrator ();
    std::unordered_map<std::string, CMD> m_commands = std::unordered_map<std::string, CMD> ();
    
    CMD         lookup_command (std::string command);
    CMD         lookup_target  (std::string target);
    void        execute        (CMD command, std::string target);
};

CMD CommanAdapter::lookup_command (std::string strCommand)
{
    switch (strCommand)
    {
        case "LIST":
            return CMD::LIST;
        case "create":
            return CMD::CREATE;
        case "drop":
            return CMD::DROP;
        case "quit":
            return CMD::QUIT;
        case "help":
        return CMD::HELP;
        default:
            std::cout<<"Command not found!\n";
            return CMD::HELP;
    }
}

TARGET CommanAdapter::lookup_target (std::string strTarget)
{
    switch (strCommand)
    {
        case "project":
            return TARGET::PROJECTS;
        case "task":
            return TARGET::TASKS;
        case "employee":
            return TARGET::EMPLS;
        default:
            std::cout<<"Target not found!\n";
    }
}


#endif // COMMANDADAPTER_HPP