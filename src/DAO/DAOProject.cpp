#include "DAOProject.hpp"


DAOProject::DAOProject ()
{
    if (query::hdl == nullptr)
        sqlite3_open("test.db", &query::hdl);
}

DAOProject::~DAOProject ()
{
    sqlite3_close(query::hdl);
}

void DAOProject::createTable () const 
{
    int err  = sqlite3_exec (query::hdl, query::CREATE_TABLE_PROJECTS, NULL, NULL, NULL);
}

void DAOProject::fillTable   () const 
{
    int err = 0;
    for (auto q: query::INSERT_INTO_PROJECTS)
    if ((err = sqlite3_exec (query::hdl, q, NULL, NULL, NULL)) != 0) {
        break;  
    }
}

DAOProject::Vect DAOProject::getAll ( ) const 
{
    Vect vect = Vect();
    int  err  = sqlite3_exec (query::hdl, "SELECT * FROM PROJECTS;", callback_select, &vect, NULL);
    return vect;
}

DAOProject::Vect DAOProject::select (TransferObject* p) const 
{
    Project* project = reinterpret_cast<Project*>(p);    
    std::string query = "SELECT * FROM PROJECTS WHERE NAME =\'" + project->get_name () + "\'";
    Vect vec = Vect();
    int err = sqlite3_exec (query::hdl, query.c_str (), callback_select, &vec, NULL);
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
    int err = sqlite3_exec (query::hdl, query.c_str (), NULL,NULL, NULL);
    //std::cout<<query<<"\n"<<sqlite3_errmsg(query::hdl)<<std::endl;
    return false;
}

void DAOProject::add (TransferObject* p) const 
{
    Project* project = reinterpret_cast<Project*>(p);    
    std::string query = "INSERT INTO PROJECTS VALUES(" + project->to_string () +  ");";
    int err = sqlite3_exec (query::hdl, query.c_str (), NULL, NULL, NULL);
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


