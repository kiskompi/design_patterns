#ifndef DAO_PROJECT
#define DAO_PROJECT

#include <vector>

#include "DAOInterface.hpp"
#include "../TRANSFER/Project.hpp"

class DAOProject: public DAOInterface {
    static int callback_select (void* used, int argc, char **argv, char **azColName);
public:
    typedef std::vector<Project> Vect;

    DAOProject ();
    DAOProject (DAOProject &&)                 = default;
    DAOProject (const DAOProject &)            = default;
    DAOProject &operator= (DAOProject &&)      = default;
    DAOProject &operator= (const DAOProject &) = default;
    ~DAOProject();

    // list all entry from the database
    virtual Vect getAll         ( ) const;
    // lists any entry from the database with the same name as the parameter
    
    virtual void createTable    () const;
    virtual void fillTable      () const;
    virtual bool update         (TransferObject* p) const;
    virtual bool deleteFromDB   (TransferObject* p) const;
    virtual void add            (TransferObject* p) const;
    virtual Vect select         (TransferObject* p) const;
};
#endif
