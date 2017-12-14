#ifndef DAO_INTERFACE
#define DAO_INTERFACE

#include <vector>
#include <sqlite3.h>
#include <iostream>
#include "../TRANSFER/Object.hpp"
#include "Query.hpp"
namespace query {
    extern sqlite3* hdl;
}


class DAOInterface
{
public:
    
    virtual ~DAOInterface 	  () = default;

    // =============
    // delete an entry from the database, which has the exact same values as the parameter Project
    // =============
    virtual bool deleteFromDB () const ; 
    // =============
    // creates a table in the database by running a query from Query.hpp
    // =============
    virtual void createTable  () const ;
    // =============
    // add an entry to the database
    // =============
    virtual void add          (const TransferObject* p) const ;
    // =============
    // fills the database by running the queries from Query.hpp
    // =============
    virtual void fillTable    (const TransferObject* p)  const;
    virtual bool update       (const TransferObject* p)  const;

};

#endif
