#ifndef ELEMENTLISTER_HPP
#define ELEMENTLISTER_HPP

#include "../DAO/DAO.hpp"
#include "Deadline.hpp"
#include "../TRANSFER/Task.hpp"
#include <type_traits>
#include <functional>

class ElementLister {
public:
	std::vector<Task> 	  list_tasks 	 ();
	std::vector<Employee> list_employees ();
	std::vector<Project>  list_projects();
	std::vector<Deadline> list_deadlines ();
};
#endif //ELEMENTLISTER_HPP
