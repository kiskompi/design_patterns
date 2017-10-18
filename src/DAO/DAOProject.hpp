#ifndef DAO_PROJECT
#define DAO_PROJECT

#include <vector>

#include "DAOInterface.hpp"
#include "../BUSINESS/Project.hpp"

class DAOProject: public DAOInterface {
    typedef std::vector<Project> Vect;
    static int callback_select (void* used, int argc, char **argv, char **azColName);
//  static int callback (void* NotUsed, int argc, char **argv, char **azColName);

public:
    DAOProject ();
    DAOProject (DAOProject &&)                = default;
    DAOProject (const DAOProject &)           = default;
    DAOProject &operator=(DAOProject &&)      = default;
    DAOProject &operator=(const DAOProject &) = default;
    ~DAOProject();


    virtual Vect getAll         (sqlite3* hdl);
    virtual void createTable    (sqlite3* hdl);
    virtual void fillTable      (sqlite3* hdl);
    virtual Vect select         (sqlite3* hdl, Object* p);
    virtual bool update         (sqlite3* hdl, Object* p);
    virtual bool deleteFromDB   (sqlite3* hdl, Object* p);
    virtual void add            (sqlite3* hdl, Object* p);

private:
    
};

DAOProject::DAOProject()
{
}

DAOProject::~DAOProject()
{
}

void DAOProject::createTable (sqlite3* hdl)
{
    int err  = sqlite3_exec (hdl, CREATE_TABLE_PROJECTS, callback, NULL, NULL);
    std::cout<<sqlite3_errmsg(hdl)<<":"<<err<<"\n";
}

void DAOProject::fillTable   (sqlite3* hdl)
{
    int err = 0;
    for (auto q: INSERT_INTO_PROJECTS)
    if ((err = sqlite3_exec (hdl, q, callback, NULL, NULL)) != 0) {
        //std::cout<<q<<"\n";
        break;
    }
}

DAOProject::Vect DAOProject::getAll (sqlite3* hdl)
{
    std::vector<Project> projects = std::vector<Project>();
    int err     = sqlite3_exec (hdl, "SELECT * FROM PROJECTS", callback_select, &projects, NULL);
    std::cout<<sqlite3_errmsg(hdl)<<":"<<projects.size()<<err<<"\n";
    
}

DAOProject::Vect DAOProject::select (sqlite3* hdl, Object* p)
{
    Project* project = reinterpret_cast<Project*>(p);    
    std::string query = "SELECT * FROM PROJECTS WHERE NAME =\'" + project->getName () + "\'";
    Vect vec = Vect();
    int err = sqlite3_exec (hdl, query.c_str (), callback_select, &vec, NULL);
    return vec;
}

bool DAOProject::update       (sqlite3* hdl, Object* p)
{
    Project* employee = reinterpret_cast<Project*>(p);    
    return false;
}

bool DAOProject::deleteFromDB (sqlite3* hdl, Object* p)
{
    Project* employee = reinterpret_cast<Project*>(p);    
    return false;
}


// =============
// add an entry to the database
// =============
void DAOProject::add (sqlite3* hdl, Object* p)
{
    Project* employee = reinterpret_cast<Project*>(p);    
    std::string query = "INSERT INTO PROJECTS VALUES(" + p->getPrintable () +  ");";
    int err = sqlite3_exec (hdl, query.c_str (), callback, NULL, NULL);
}


// =============
// callback function for SELECT queries. Populates a vector passed in as a pointer
// Params:
// @param void* used: the parameter passed from sqlite3_exec
// @param int argc  : the # of columns
// @param char** argv: the returned char[] from the current step
// @param char** azColName: the names of the columns
// =============
int DAOProject::callback_select (void* used, int argc, char **argv, char**azColName){
    std::vector<Project>* projects = static_cast<std::vector<Project>*>(used);
    for(size_t i = 0; i<argc; i++) {
        projects->emplace_back(Project(argv[0], argv[1]));
    }
    return 0;
}

#endif