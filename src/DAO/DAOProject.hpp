#ifndef DAO_PROJECT
#define DAO_PROJECT

#include <vector>

#include "DAOInterface.hpp"
#include "../BUSINESS/Project.hpp"

class DAOProject: public DAOInterface {
    typedef std::vector<Project> Vect;
    static int callback_select (void* used, int argc, char **argv, char **azColName);

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
    
static int callback(void* used, int argc, char **argv, char**azColName){
    std::cout<<"kai\n";
    return 0;
}
};

DAOProject::DAOProject()
{
}

DAOProject::~DAOProject()
{
}

void DAOProject::createTable (sqlite3* hdl)
{
    int err  = sqlite3_exec (hdl, CREATE_TABLE_PROJECTS, NULL, NULL, NULL);
}

void DAOProject::fillTable   (sqlite3* hdl)
{
    int err = 0;
    for (auto q: INSERT_INTO_PROJECTS)
    if ((err = sqlite3_exec (hdl, q, NULL, NULL, NULL)) != 0) {
        //std::cout<<q<<"\n";
        break;
    }
}

DAOProject::Vect DAOProject::getAll (sqlite3* hdl)
{
    Vect vect = Vect();
    int  err  = sqlite3_exec (hdl, "SELECT * FROM PROJECTS;", callback_select, &vect, NULL);
    return vect;
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
    Project* project = reinterpret_cast<Project*>(p);
    std::string query = "DELETE FROM PROJECTS WHERE NAME =\'"
                      + project->getName () + "\' AND DESC = \'" 
                      + project->getDesc () + "\';";
    int err = sqlite3_exec (hdl, query.c_str (), NULL,NULL, NULL);
    std::cout<<query<<"\n"<<sqlite3_errmsg(hdl)<<std::endl;
    return false;
}


// =============
// add an entry to the database
// =============
void DAOProject::add (sqlite3* hdl, Object* p)
{
    Project* project = reinterpret_cast<Project*>(p);    
    std::string query = "INSERT INTO PROJECTS VALUES(" + project->getPrintable () +  ");";
    int err = sqlite3_exec (hdl, query.c_str (), callback, &query, NULL);
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
    std::vector<Project>* projects = reinterpret_cast<std::vector<Project>*>(used);
    projects->emplace_back(Project(std::string(argv[0]), std::string(argv[1])));
    return 0;
}

#endif