#ifndef DAO_EMPLOYEE
#define DAO_EMPLOYEE

#include <vector>
#include "DAOInterface.hpp"
#include "../BUSINESS/Employee.hpp"

class DAOEmployee: public DAOInterface
{
    typedef std::vector<Employee> Vect;
    
    static int callback_select (void* used, int argc, char **argv, char**azColName);
    static int callback        (void* NotUsed, int argc, char **argv, char **azColName);
    
public:
    DAOEmployee ();
    DAOEmployee (DAOEmployee &&) {}
    DAOEmployee (const DAOEmployee& p) {}
    //virtual DAOEmployee &operator=(DAOEmployee && p) {return DAOEmployee ();}
    //virtual DAOEmployee &operator=(const DAOEmployee & p) {return DAOEmployee ();}
    virtual ~DAOEmployee();


    virtual Vect getAll       (sqlite3* hdl);
    virtual void createTable  (sqlite3* hdl);
    virtual void fillTable    (sqlite3* hdl);
    virtual Vect select       (sqlite3* hdl, Object* p);
    virtual void add          (sqlite3* hdl, Object* e);
    virtual bool update       (sqlite3* hdl, Object* e);
    virtual bool deleteFromDB (sqlite3* hdl, Object* e);

private:
    
};

DAOEmployee::DAOEmployee  ()
{
}

DAOEmployee::~DAOEmployee ()
{
}

DAOEmployee::Vect DAOEmployee::getAll (sqlite3* hdl)
{
    char const* data = "selection started";
    Vect res         = Vect();
    int err          = sqlite3_exec (hdl, "SELECT * FROM EMPLOYEES", callback_select, &res, NULL);
    return res;
}


void DAOEmployee::createTable   (sqlite3* hdl)
{
    int err = sqlite3_exec (hdl, CREATE_TABLE_EMPLOYEES, callback, NULL, NULL);
}

void DAOEmployee::fillTable     (sqlite3* hdl) 
{
    int err = 0;
    for (auto q: INSERT_INTO_EMPLOYEES){
        // std::cout << q << "\n";
        
        if ((err = sqlite3_exec (hdl, q, callback, NULL, NULL)) != 0)
            break;
    }
}

void DAOEmployee::add       (sqlite3* hdl, Object* p) 
{
    Employee* employee = reinterpret_cast<Employee*>(p);
    std::string query = 
        "INSERT INTO EMPLOYEES VALUES(" + p->getPrintable () + ");";
    int err = sqlite3_exec (hdl, query.c_str (), callback, NULL, NULL);    
    if (err != 0)
        std::cout<<sqlite3_errmsg(hdl)<<"\n";    
}
bool DAOEmployee::update      (sqlite3* hdl, Object* p)
{
    Employee* employee = reinterpret_cast<Employee*>(p);
    return false;
}

bool DAOEmployee::deleteFromDB  (sqlite3* hdl, Object* p)
{
    Employee* employee = reinterpret_cast<Employee*>(p);
    std::string query = 
    "DELETE FROM EMPLOYEES VALUES(" + p->getPrintable () + ");";
    int err = sqlite3_exec (hdl, query.c_str (), callback, NULL, NULL);    
    if (err != 0)
        std::cout<<sqlite3_errmsg(hdl)<<"\n";    
}

DAOEmployee::Vect DAOEmployee::select  (sqlite3* hdl, Object* p)
{
    Employee* employee = reinterpret_cast<Employee*>(p);
    std::string query = "SELECT * FROM EMPLOYEES WHERE NAME =\'" + employee->getName () + "\'";
    Vect vec = Vect();
    int err = sqlite3_exec (hdl, query.c_str (), callback_select, &vec, NULL);
    return vec;
}

int DAOEmployee::callback       (void* NotUsed, int argc, char **argv, char **azColName) 
{
    return 0;
}

int DAOEmployee::callback_select (void* used, int argc, char **argv, char**azColName)
{
    std::vector<Employee>* projects = reinterpret_cast<std::vector<Employee>*>(used);
    for(size_t i = 0; i<argc; i++) {
        projects->emplace_back(Employee(argv[0], argv[1], argv[2], argv[3]));
    }
    return 0;
}

#endif