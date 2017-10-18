#include "../DAO/DAOFactory.hpp"
#include "../DAO/DAOEmployee.hpp"
#include "../DAO/DAOTask.hpp"
#include "../DAO/DAOProject.hpp"

int main () {
    sqlite3 *hdl;
    sqlite3_open16("test.db", &hdl);

    DAOFactory df = DAOFactory();
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
    Object* t = new Task     ("Vármodell", "3D modellezés", "10", "2012-01-01", "Az egri vár 3D modelljének kidolgozása.");
    Object* p = new Project  ("Muhi csata", "János");
    
    std::cout<<"testing add()\n";
    daoEmp    ->add (hdl, e);
    daoTask   ->add (hdl, t);
    daoProject->add (hdl, p);
    
    std::cout<<"testing select()\n";
    std::vector<Employee > employees = daoEmp     -> select(hdl, e);
    std::vector<Task >     tasks     = daoTask    -> select(hdl, t);
    std::vector<Project >  projects  = daoProject -> select(hdl, p);
    
    std::cout<<"testing getAlly()\n";
    std::vector<Employee > employees2 = daoEmp     -> getAll(hdl);
    std::vector<Task >     tasks2     = daoTask    -> getAll(hdl);
    std::vector<Project >  projects2  = daoProject -> getAll(hdl);

    std::cout<<"# of employees: "<<employees.size()<<"\n";
    std::cout<<"# of selected projects: "<<projects.size()<<"\n"; 
    for (auto i: projects){
        std::cout << i . getName() << "\n";
    }
    sqlite3_close (hdl);
    return 0;
}