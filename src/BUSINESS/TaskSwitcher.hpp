#ifndef TSKSWITCHER_H
#define TSKSWITCHER_H
#include "../TRANSFER/Employee.hpp"
#include "../DAO/DAO.hpp"

class TaskSwitcher {
	public:
    short switch_tasks (std::string& t1str, std::string& t2str);
 };

#endif
