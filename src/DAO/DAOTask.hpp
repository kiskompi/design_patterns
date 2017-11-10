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

DAOTask::DAOTask ()
{
    if (hdl == nullptr)
        sqlite3_open("test.db", &hdl);
}

DAOTask::~DAOTask()
{
    sqlite3_close(hdl);
}

DAOTask::Vect DAOTask::getAll ( ) const
{
    Vect vect = Vect();
    int err   = sqlite3_exec (hdl, "SELECT * FROM TASKS;", callback_select, &vect, NULL);
    return vect;
}

void DAOTask::createTable     ( ) const
{
    int err = sqlite3_exec (hdl, query::CREATE_TABLE_TASKS, NULL, NULL, NULL);
}

void DAOTask::fillTable       ( ) const
{
    int err = 0;
    for (auto q: query::INSERT_INTO_TASKS)
        if ((err = sqlite3_exec (hdl, q, NULL,  NULL, NULL)) != 0) {
            break;
        }
}

void DAOTask::add (TransferObject* t) const
{
    Task* task = reinterpret_cast<Task*>(t);
    std::string query = "INSERT INTO TASKS VALUES(" + task->to_string () + ");";
    int err = sqlite3_exec (hdl, query.c_str (), NULL, NULL, NULL);
}

bool DAOTask::update        (TransferObject* t) const
{
    Task* task = reinterpret_cast<Task*>(t);
    return false;
}

void DAOTask::assign (const Employee& empl, Task& task) const
{
    const std::string query = "INSERT INTO TASKS_EMPLOYEES(" + task.to_string () + ", " + empl.to_string () + ");";
    int err = sqlite3_exec (hdl, query.c_str (), NULL, NULL, NULL);
    if (err == 0)
        task.assign_to (empl);
}

bool DAOTask::deleteFromDB    (TransferObject* t) const
{
    Task* task = reinterpret_cast<Task*>(t);
    std::string query = "DELETE FROM TASKS WHERE NAME =\'"
    + task->get_name     () + "\' AND TYPE = \'" 
    + task->get_type     () + "\' AND DESC = \'" 
    + task->get_desc     () + "\' AND DEADLINE = \'" 
    + task->get_deadline () + "\';";
    int err = sqlite3_exec (hdl, query.c_str (), NULL,NULL, NULL);
    // std::cout<<query<<"\n"<<sqlite3_errmsg(hdl)<<std::endl;
    return false;
}

DAOTask::Vect DAOTask::select (TransferObject* t) const
{
    Task* task = reinterpret_cast<Task*>(t);
    std::string query = "SELECT * FROM TASKS WHERE NAME =\'" + task->get_name () + "\'";
    Vect vec = Vect();
    int err = sqlite3_exec (hdl, query.c_str (), callback_select, &vec, NULL);
    return vec;
}

int DAOTask::callback_select (void* used, int argc, char **argv, char**azColName)
{
    std::vector<Task>* projects = reinterpret_cast<std::vector<Task>*>(used);
    std::string a(argv[0]); 
    std::string s(argv[1]); 
    std::string d(argv[2]); 
    std::string f(argv[3]); 
    std::string g(argv[4]?argv[4]:"NULL"); 
    std::string h(argv[5]?argv[5]:"NULL");
    projects->emplace_back(Task(
        a,s,d,f,g,h
        ));
    return 0;
}
void  DAOTask::create_table_tasks_employees () const {
        const std::string query = "CREATE TABLE IF NOT EXISTS TASKS_EMPLOYEES(TASK CHAR[50], EMPLOYEE CHAR[50]);";
        const char* qu = {query.c_str ()};
        char* errms = 0;
        int err = sqlite3_exec (hdl, query.c_str (), NULL, NULL, &errms);
        std::cout<<errms<<std::endl;
    }
#endif