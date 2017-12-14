#include "TaskLister.hpp"

std::vector<Task> TaskLister::list (const std::string str = "") const
{
	const auto dao = DAOTask ();
	const auto elem_vec = dao.getAll ();
	return elem_vec;
}
