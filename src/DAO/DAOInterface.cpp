#include "DAOInterface.hpp"

// =============
// delete an entry from the database, which has the exact same values as the parameter Project
// =============
 bool DAOInterface::deleteFromDB () const {return false;} 
// =============
// creates a table in the database by running a query from Query.hpp
// =============
 void DAOInterface::createTable  () const {}
// =============
// add an entry to the database
// =============
 void DAOInterface::add          (const TransferObject* p) const  {}
// =============
// fills the database by running the queries from Query.hpp
// =============
 void DAOInterface::fillTable    (const TransferObject* p) const {}
 bool DAOInterface::update       (const TransferObject* p) const {
	 return false;
 }

