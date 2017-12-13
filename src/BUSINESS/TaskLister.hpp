#ifndef TASKLISTER_H
#define TASKLISTER_H
#include "ElementLister.hpp"
#include <vector>
class TaskLister: public ElementLister {
public:
    std::vector<Task> list (const std::string& str = "") const
	{
		const auto dao = DAOTask ();
    	const auto elem_vec = dao.getAll ();
		return elem_vec;
	}
    	
};

#endif
