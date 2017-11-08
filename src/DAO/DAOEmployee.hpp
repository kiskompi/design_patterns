#ifndef DAO_EMPLOYEE
#define DAO_EMPLOYEE

#include <vector>
#include "DAOInterface.hpp"
#include "../TRANSFER/Employee.hpp"


class DAOEmployee: public DAOInterface
{
    typedef std::vector<Employee> Vect;
    
    static int callback_select (void* used, int argc, char **argv, char**azColName);
    sqlite3* hdl;

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

DAOEmployee::DAOEmployee  ()
{
    sqlite3_open("test.db", &hdl);
}

DAOEmployee::~DAOEmployee ()
{
    sqlite3_close(hdl);
}

DAOEmployee::Vect DAOEmployee::getAll ( ) const
{
    Vect res = Vect();
    int err  = sqlite3_exec (hdl, "SELECT * FROM EMPLOYEES;", callback_select, &res, NULL);
    return res;
}


void DAOEmployee::createTable   ( ) const
{
    int err = sqlite3_exec (hdl, query::CREATE_TABLE_EMPLOYEES, NULL, NULL, NULL);
}

void DAOEmployee::fillTable     ( )  const
{
    int err = 0;
    for (auto q: query::INSERT_INTO_EMPLOYEES){
        // std::cout << q << "\n";
        
        if ((err = sqlite3_exec (hdl, q, NULL, NULL, NULL)) != 0)
            break;
    }
}


void DAOEmployee::add (TransferObject* p)  const
{
    Employee* employee = reinterpret_cast<Employee*>(p);
    std::string query = "INSERT INTO EMPLOYEES VALUES(" + employee->to_string () + ");";
    int err = sqlite3_exec (hdl, query.c_str (), NULL, NULL, NULL);

}

bool DAOEmployee::update      (TransferObject* p) const
{
    Employee* employee = reinterpret_cast<Employee*>(p);
    return false;
}

bool DAOEmployee::deleteFromDB  (TransferObject* p) const
{
    Employee* emp = reinterpret_cast<Employee*>(p);
    std::string query = "DELETE FROM EMPLOYEES WHERE NAME =\'"
                      + emp->get_name () + "\' AND ADDRESS = \'" 
                      + emp->get_address () + "\' AND EMAIL = \'" 
                      + emp->get_email () + "\' AND PHONE = \'" 
                      + emp->get_phone () + "\';";
    int err = sqlite3_exec (hdl, query.c_str (), NULL,NULL, NULL);
    //std::cout<<query<<"\n"<<sqlite3_errmsg(hdl)<<std::endl;
    
}

DAOEmployee::Vect DAOEmployee::select  (TransferObject* p) const
{
    Employee* employee = reinterpret_cast<Employee*>(p);
    std::string query = "SELECT * FROM EMPLOYEES WHERE NAME =\'" + employee->get_name () + "\'";
    Vect vec = Vect();
    int err = sqlite3_exec (hdl, query.c_str (), callback_select, &vec, NULL);
    return vec;
}


int DAOEmployee::callback_select (void* used, int argc, char **argv, char**azColName)
{
    std::vector<Employee>* employees = reinterpret_cast<std::vector<Employee>*>(used);
    employees->emplace_back(Employee(argv[0], argv[1], argv[2], argv[3]));
    return 0;
}

#endif