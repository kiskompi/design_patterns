#ifndef TASKLISTER_H
#define TASKLISTER_H
#include "ElementLister.hpp"
#include <vector>


class DeadlineLister: public ElementLister {
public:
    std::vector<Deadline> list () const {
        std::vector<Task> 	  tasks = list<Task> ();
        std::vector<Deadline> deadlines;
        for (const auto& task: tasks)
            deadlines.push_back (task.get_deadline ());
        return deadlines;
    }	
   	
};

#endif
