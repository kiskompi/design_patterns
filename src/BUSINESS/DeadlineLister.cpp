#include "DeadlineLister.hpp"
#include "TaskLister.hpp"

std::vector<Deadline> DeadlineLister::list () const {
	DAOFactory df = DAOFactory ();
	DAOTask dt = df.get<DAOTask> ();
	std::vector<Task> 	  tasks = dt.getAll ();
	std::vector<Deadline> deadlines;
	for (const auto& task: tasks)
		deadlines.push_back (task.get_deadline ());
	return deadlines;
}	

