#ifndef DAO_INTERFACE
#define DAO_INTERFACE

#include <vector>
#include <sqlite3.h>
#include <iostream>
#include "../BUSINESS/Object.hpp"
#include "Query.hpp"

class DAOInterface
{
    // typedef std::vector<Object*> Vect;
public:
    
    //virtual DAOInterface &operator= (DAOInterface &&) = 0;
    //virtual DAOInterface &operator= (const DAOInterface &) = 0;
    virtual ~DAOInterface (){};

    //virtual void addToDB (sqlite3*, Object*)      = 0;
//    virtual Vect getAll         (sqlite3* hdl)              {}
    virtual bool deleteFromDB   (sqlite3* hdl)              {}
    virtual void createTable    (sqlite3* hdl)              {}
//    virtual Vect select         (sqlite3* hdl, Object* p)   {}
    virtual void add            (sqlite3* hdl, Object* p)   {}
    virtual bool update         (sqlite3* hdl, Object* p)   {}
    virtual void fillTable      (sqlite3* hdl, Object* p)   {}

private:

};

#endif