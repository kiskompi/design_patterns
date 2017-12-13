#ifndef ELEMENTLISTER_HPP
#define ELEMENTLISTER_HPP

#include "../DAO/DAO.hpp"
#include "Deadline.hpp"
#include "../TRANSFER/Task.hpp"
#include <type_traits>

class ElementLister {
public:
	std::vector<TransferObject> list ();
};

#endif //ELEMENTLISTER_HPP
