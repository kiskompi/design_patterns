#include "ElementLister.hpp"
std::vector<Task> ElementLister::list_tasks (){
	DAOFactory df = DAOFactory ();
	DAOTask    dt = df.get<DAOTask> ();
	return dt.getAll ();
}

std::vector<Project> ElementLister::list_projects (){
	DAOFactory df = DAOFactory ();
	DAOProject dt = df.get<DAOProject> ();
	return dt.getAll ();
}

std::vector<Employee> ElementLister::list_employees (){
	DAOFactory 	df = DAOFactory ();
	DAOEmployee dt = df.get<DAOEmployee> ();
	return dt.getAll ();
}
	
std::vector<Deadline> ElementLister::list_deadlines () {
	DAOFactory df = DAOFactory ();
	DAOTask dt = df.get<DAOTask> ();
	std::vector<Task> 	  tasks = dt.getAll ();
	std::vector<Deadline> deadlines;
	for (const auto& task: tasks)
		deadlines.push_back (task.get_deadline ());
	return deadlines;

}

