#ifndef TASKLISTER_H
#define TASKLISTER_H
#include "ElementLister.hpp"
#include <vector>
class TaskLister: public ElementLister {
public:
	TaskLister () = default;
    std::vector<Task> list (const std::string /*str = ""*/) const ;
    	
};

#endif
