#include "../DAO/DAOFactory.hpp"
#include "../DAO/DAOEmployee.hpp"
#include "../DAO/DAOTask.hpp"
#include "../DAO/DAOProject.hpp"

int main () {

    DAOFactory    df         = DAOFactory();

    DAOEmployee*  daoEmp     = df.get<DAOEmployee>();
    DAOTask*      daoTask    = df.get<DAOTask>();
    DAOProject*   daoProject = df.get<DAOProject>();
    df.Initialize ();
    
    daoEmp     -> createTable();
    daoTask    -> createTable();
    daoProject -> createTable();
    //daoEmp     -> fillTable  (hdl);
    //daoTask    -> fillTable  (hdl);
    //daoProject -> fillTable  (hdl);
    
    TransferObject* e = new Employee ("Aladar", "Adress", "amail", "phone");
    TransferObject* t = new Task     ("Varmodell", "3D modellezes", "10", "2012-01-01", "Az egri var 3D modelljenek kidolgozasa.", "Egri csata ");
    TransferObject* p = new Project  ("Muhi csata", "Janos");
    
    std::cout<<"testing add()\n";
    daoProject->add (p);
    daoEmp    ->add (e);
    daoTask   ->add (t);
    
    std::cout<<"testing select()\n";
    std::vector<Project >  projects  = daoProject -> select(p);
    std::vector<Employee > employees = daoEmp     -> select(e);
    std::vector<Task >     tasks     = daoTask    -> select(t);

    daoProject -> deleteFromDB(p);
    daoEmp     -> deleteFromDB(e);
    daoTask    -> deleteFromDB(t);
    
    std::cout<<"testing getAll()\n";
    std::vector<Employee > employees2 = daoEmp     -> getAll();
    std::vector<Task >     tasks2     = daoTask    -> getAll();
    std::vector<Project >  projects2  = daoProject -> getAll();

    std::cout<<"# of selected employees: "<<employees.size()<<"\n";
    std::cout<<"# of selected projects: " <<projects.size()<<"\n"; 
    std::cout<<"# of selected tasks: "    <<tasks.size()<<"\n"; 
    
    std::cout<<"# of employees: "<<employees2.size()<<"\n";
    std::cout<<"# of projects: " <<projects2.size()<<"\n"; 
    std::cout<<"# of tasks: "    <<tasks2.size()<<"\n"; 
    for (auto i: tasks){
        std::cout << i.get_name() <<" "<< i.get_desc() <<" "<< "\n";
    }
    return 0;
}