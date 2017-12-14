#ifndef DAO_INTERFACE
#define DAO_INTERFACE

#include <vector>
#include <sqlite3.h>
#include <iostream>
#include "../TRANSFER/Object.hpp"
#include "Query.hpp"
namespace query {
    sqlite3* hdl = nullptr;
}

class DAOInterface
{
public:
    
    virtual ~DAOInterface (){};

    virtual void add        (const TransferObject*) const {}
    // =============
    // delete an entry from the database, which has the exact same values as the parameter Project
    // =============
    virtual bool deleteFromDB   (sqlite3* hdl) const {return false;}; 
    // =============
    // creates a table in the database by running a query from Query.hpp
    // =============
    virtual void createTable    (sqlite3* hdl) const {}
    // =============
    // add an entry to the database
    // =============
    virtual void add            (const TransferObject* p)   {}
    // =============
    // fills the database by running the queries from Query.hpp
    // =============
    virtual void fillTable      (const TransferObject* p)  const {}
    virtual bool update         (const TransferObject* p)  const {return false;}
private:

};

#endif
