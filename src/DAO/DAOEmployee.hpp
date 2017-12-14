#ifndef DAO_EMPLOYEE
#define DAO_EMPLOYEE

#include <vector>
#include "DAOInterface.hpp"
#include "../TRANSFER/Employee.hpp"


class DAOEmployee: public DAOInterface
{
    typedef std::vector<Employee> Vect;
    
    static int callback_select (void* used, int argc, char **argv, char**azColName);
    sqlite3* hdl = query::hdl;

public:
    DAOEmployee ();
    DAOEmployee (DAOEmployee &&) {}
    DAOEmployee (const DAOEmployee& p) {}
    virtual ~DAOEmployee();


    virtual Vect getAll       () const;
    virtual void createTable  () const;
    virtual void fillTable    () const;
    virtual Vect select       (TransferObject* p) const;
    virtual void add          (TransferObject* e) const;
    virtual bool update       (TransferObject* e) const;
    virtual bool deleteFromDB (TransferObject* e) const;
};
#endif
