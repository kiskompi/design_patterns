#ifndef DAO_INTERFACE
#define DAO_INTERFACE

#include <vector>
#include <sqlite3.h>
#include <iostream>
#include "../BUSINESS/Object.hpp"
#include "Query.hpp"

class DAOInterface
{
public:
    
    virtual ~DAOInterface (){};

    virtual void addToDB        (sqlite3*, const Object*)     {}
    // =============
    // delete an entry from the database, which has the exact same values as the parameter Project
    // =============
    virtual bool deleteFromDB   (sqlite3* hdl)          {}
    // =============
    // creates a table in the database by running a query from Query.hpp
    // =============
    virtual void createTable    (sqlite3* hdl)          {}
    // =============
    // add an entry to the database
    // =============
    virtual void add            (sqlite3* hdl, const Object* p)   {}
    // =============
    // fills the database by running the queries from Query.hpp
    // =============
    virtual void fillTable      (sqlite3* hdl, const Object* p)   {}
    virtual bool update         (sqlite3* hdl, const Object* p)   {}
private:

};

#endif