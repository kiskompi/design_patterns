#ifndef DAO_PROJECT
#define DAO_PROJECT

#include <vector>

#include "DAOInterface.hpp"
#include "../TRANSFER/Project.hpp"

class DAOProject: public DAOInterface {
    static int callback_select (void* used, int argc, char **argv, char **azColName);
    sqlite3* hdl = query::hdl;
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

DAOProject::DAOProject ()
{
    if (hdl == nullptr)
        sqlite3_open("test.db", &hdl);
}

DAOProject::~DAOProject ()
{
    sqlite3_close(hdl);
}

void DAOProject::createTable () const 
{
    int err  = sqlite3_exec (hdl, query::CREATE_TABLE_PROJECTS, NULL, NULL, NULL);
}

void DAOProject::fillTable   () const 
{
    int err = 0;
    for (auto q: query::INSERT_INTO_PROJECTS)
    if ((err = sqlite3_exec (hdl, q, NULL, NULL, NULL)) != 0) {
        break;  
    }
}

DAOProject::Vect DAOProject::getAll ( ) const 
{
    Vect vect = Vect();
    int  err  = sqlite3_exec (hdl, "SELECT * FROM PROJECTS;", callback_select, &vect, NULL);
    return vect;
}

DAOProject::Vect DAOProject::select (TransferObject* p) const 
{
    Project* project = reinterpret_cast<Project*>(p);    
    std::string query = "SELECT * FROM PROJECTS WHERE NAME =\'" + project->get_name () + "\'";
    Vect vec = Vect();
    int err = sqlite3_exec (hdl, query.c_str (), callback_select, &vec, NULL);
    return vec;
}

bool DAOProject::update       (TransferObject* p) const 
{
    Project* employee = reinterpret_cast<Project*>(p);    
    return false;
}


bool DAOProject::deleteFromDB (TransferObject* p) const 
{
    Project* project = reinterpret_cast<Project*>(p);
    std::string query = "DELETE FROM PROJECTS WHERE NAME =\'"
                      + project->get_name () + "\' AND DESC = \'" 
                      + project->get_desc () + "\';";
    int err = sqlite3_exec (hdl, query.c_str (), NULL,NULL, NULL);
    //std::cout<<query<<"\n"<<sqlite3_errmsg(hdl)<<std::endl;
    return false;
}

void DAOProject::add (TransferObject* p) const 
{
    Project* project = reinterpret_cast<Project*>(p);    
    std::string query = "INSERT INTO PROJECTS VALUES(" + project->to_string () +  ");";
    int err = sqlite3_exec (hdl, query.c_str (), NULL, NULL, NULL);
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