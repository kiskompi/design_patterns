#ifndef TASKLISTER_H
#define TASKLISTER_H
#include "ElementLister.hpp"
#include <vector>


class EmployeeLister: public ElementLister {
public:
    std::vector<Employee&> list (const std::string& str = "") const -> 
	{
		const auto dao = DAOEmployee ();
    	const auto elem_vec = dao.getAll ();
		return elem_vec;
	}
};

#endif
