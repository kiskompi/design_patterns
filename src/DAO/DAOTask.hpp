#ifndef DAO_TASK
#define DAO_TASK

#include "DAOInterface.hpp"
#include "../BUSINESS/Task.hpp"

class DAOTask: public DAOInterface
{
    typedef std::vector<Task> Vect;
    static int callback_select(void* used, int argc, char **argv, char**azColName);

public:
    DAOTask();
    DAOTask(DAOTask &&) = default;
    DAOTask(const DAOTask &) = default;
    DAOTask &operator=(DAOTask &&) = default;
    DAOTask &operator=(const DAOTask &) = default;
    ~DAOTask();

    virtual Vect getAll       (sqlite3* hdl);
    virtual void createTable  (sqlite3* hdl);
    virtual void fillTable    (sqlite3* hdl);
    virtual Vect select       (sqlite3* hdl, Object* t);
    virtual void add          (sqlite3* hdl, Object* t);
    virtual bool update       (sqlite3* hdl, Object* t);
    virtual bool deleteFromDB (sqlite3* hdl, Object* t);

private:
    
};

DAOTask::DAOTask ()
{
}

DAOTask::~DAOTask()
{
}

DAOTask::Vect DAOTask::getAll (sqlite3* hdl)
{
    int err = sqlite3_exec (hdl, "SELECT * FROM PROJECTS", callback, NULL, NULL);
    std::cout<<sqlite3_errmsg(hdl)<<":"<<err<<"\n";
}

void DAOTask::createTable     (sqlite3* hdl)
{
    int err = sqlite3_exec (hdl, CREATE_TABLE_TASKS, callback, NULL, NULL);
    std::cout<<sqlite3_errmsg(hdl)<<":"<<err<<"\n";
}

void DAOTask::fillTable       (sqlite3* hdl)
{
    int err = 0;
    for (auto q: INSERT_INTO_TASKS)
        if ((err = sqlite3_exec (hdl, q, callback,  NULL, NULL)) != 0) {
            std::cout<<q<<"\n";
            break;
        }
}

void DAOTask::add         (sqlite3* hdl, Object* t)
{
    Task* task = reinterpret_cast<Task*>(t);
    std::string query = 
        "INSERT INTO TASKS VALUES(" + task->getPrintable () + ");";
    int err = sqlite3_exec (hdl, query.c_str (), callback, NULL, NULL);
    if (err != 0)
        std::cout<<sqlite3_errmsg(hdl)<<"\n";
}

bool DAOTask::update        (sqlite3* hdl, Object* t)
{
    Task* task = reinterpret_cast<Task*>(t);
    return false;
}

bool DAOTask::deleteFromDB    (sqlite3* hdl, Object* t)
{
    Task* task = reinterpret_cast<Task*>(t);
    return false;
}

DAOTask::Vect DAOTask::select (sqlite3* hdl, Object* t)
{
    Task* task = reinterpret_cast<Task*>(t);
    std::string query = "SELECT * FROM TASKS WHERE NAME =\'" + task->getName () + "\'";
    Vect vec = Vect();
    int err = sqlite3_exec (hdl, query.c_str (), callback_select, &vec, NULL);
    return vec;
}

int DAOTask::callback_select (void* used, int argc, char **argv, char**azColName)
{
    std::vector<Task>* projects = reinterpret_cast<std::vector<Task>*>(used);
    for(size_t i = 0; i<argc; i++) {
        projects->emplace_back(Task(
            std::string(argv[0]), 
            std::string(argv[1]), 
            std::string(argv[2]), 
            std::string(argv[3]), 
            std::string(argv[4])));
    }
    return 0;
}
#endif