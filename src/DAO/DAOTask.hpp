#ifndef DAO_TASK
#define DAO_TASK

#include <functional>
#include "DAOInterface.hpp"
#include "../TRANSFER/Task.hpp"

class DAOTask: public DAOInterface
{
    typedef std::vector<Task> Vect;
    static int callback_select(void* used, int argc, char **argv, char**azColName);
    sqlite3* hdl = query::hdl;

public:
    DAOTask();
    DAOTask(DAOTask &&)                 = default;
    DAOTask(const DAOTask &)            = default;
    DAOTask &operator=(DAOTask &&)      = default;
    DAOTask &operator=(const DAOTask &) = default;
    ~DAOTask();
    
    // TODO add a Project field
    virtual Vect getAll       () const;
    virtual void createTable  () const;
    virtual void fillTable    () const;
    virtual Vect select       (TransferObject* t) const;
    virtual void add          (TransferObject* t) const;
    virtual bool update       (TransferObject* t) const;
    virtual bool deleteFromDB (TransferObject* t) const;
    void         assign       (const Employee& empl, Task& task) const;
    void         create_table_tasks_employees () const;
};
#endif
