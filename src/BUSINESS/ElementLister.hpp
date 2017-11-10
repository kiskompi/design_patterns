class ElementLister {
public:
    std::vector<Project>  list_projects  () const {
    	// create DAO
    	// use dao
    	return m_projects;
    }
    std::vector<Task>     list_tasks     () const {return m_tasks;   }
    std::vector<Employee> list_employees () const {return m_empls;   }
    std::vector<Deadline> list_deadlines () const ;	
};


std::vector<Deadline> Administrator::list_deadlines () const {
    std::vector<Deadline> deadlines;
    for (const auto& task: m_tasks)
        deadlines.push_back (task.get_deadline ());
    return deadlines;
}

