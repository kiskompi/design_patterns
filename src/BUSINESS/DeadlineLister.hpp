#ifndef TASKLISTER_H
#define TASKLISTER_H
#include "ElementLister.hpp"
#include <vector>


class DeadlineLister: public ElementLister {
public:
    std::vector<Deadline> list () const; 
};

#endif
