#include "../DAO/DAOFactory.hpp"
#include "../DAO/DAOEmployee.hpp"
#include "../DAO/DAOTask.hpp"
#include "../DAO/DAOProject.hpp"

int main () {
    sqlite3 *hdl;
    sqlite3_open("test.db", &hdl);

    DAOFactory    df         = DAOFactory();

    DAOEmployee*  daoEmp     = df.getDAO<DAOEmployee>();
    DAOTask*      daoTask    = df.getDAO<DAOTask>();
    DAOProject*   daoProject = df.getDAO<DAOProject>();
    df.Initialize ();
    
    daoEmp     -> createTable(hdl);
    daoTask    -> createTable(hdl);
    daoProject -> createTable(hdl);
    //daoEmp     -> fillTable  (hdl);
    //daoTask    -> fillTable  (hdl);
    //daoProject -> fillTable  (hdl);
    
    Object* e = new Employee ("Aladar", "Adress", "amail", "phone");
    Object* t = new Task     ("Varmodell", "3D modellezes", "10", "2012-01-01", "Az egri var 3D modelljenek kidolgozasa.");
    Object* p = new Project  ("Muhi csata", "Janos");
    
    std::cout<<"testing add()\n";
    daoProject->add (hdl, p);
    daoEmp    ->add (hdl, e);
    daoTask   ->add (hdl, t);
    
    std::cout<<"testing select()\n";
    std::vector<Project >  projects  = daoProject -> select(hdl, p);
    std::vector<Employee > employees = daoEmp     -> select(hdl, e);
    std::vector<Task >     tasks     = daoTask    -> select(hdl, t);

    daoProject -> deleteFromDB(hdl, p);
    daoEmp     -> deleteFromDB(hdl, e);
    daoTask    -> deleteFromDB(hdl, t);
    
    std::cout<<"testing getAll()\n";
    std::vector<Employee > employees2 = daoEmp     -> getAll(hdl);
    std::vector<Task >     tasks2     = daoTask    -> getAll(hdl);
    std::vector<Project >  projects2  = daoProject -> getAll(hdl);

    std::cout<<"# of selected employees: "<<employees.size()<<"\n";
    std::cout<<"# of selected projects: " <<projects.size()<<"\n"; 
    std::cout<<"# of selected tasks: "    <<tasks.size()<<"\n"; 
    
    std::cout<<"# of employees: "<<employees2.size()<<"\n";
    std::cout<<"# of projects: " <<projects2.size()<<"\n"; 
    std::cout<<"# of tasks: "    <<tasks2.size()<<"\n"; 
    for (auto i: projects){
        std::cout << i.getName() << "\n";
    }
    sqlite3_close (hdl);
    return 0;
}