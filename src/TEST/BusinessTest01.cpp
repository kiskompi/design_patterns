#include "../BUSINESS/Administrator.hpp"
# include <iostream>
int main () {
    Administrator& admin = Administrator::make_admin ();

    admin.make_element (std::vector<std::string>{"Aladar", "Adress", "amail", "phone"});
    admin.make_element (
		std::vector<std::string> {
			"Varmodell", 
			"3D modellezes", 
			"10", "2012-01-01", 
			"Az egri var 3D modelljenek kidolgozasa.", 
			"Egri csata "
		});
    admin.make_element (std::vector<std::string>{"Muhi csata", "Janos"});
    
    std::vector<Project>  prjcs = admin.list<DAOProject>  ();
    std::vector<Task>     tasks = admin.list<DAOTask>	   ();
    std::vector<Employee> empls = admin.list<DAOEmployee> ();
    std::vector<Deadline> ddlns = admin.list<Deadline> ();

    for (auto& i: prjcs)
        std::cout<<i.to_string ()<<std::endl;
    for (auto& i: tasks)
        std::cout<<i.to_string ()<<std::endl;
    for (auto& i: empls)
        std::cout<<i.to_string ()<<std::endl;
    for (auto& i: ddlns)
        std::cout<<i.to_string ()<<std::endl;

    admin.drop<Employee>("Aladar");
    admin.drop<Task>    ("Varmodell");
    admin.drop<Project> ("Muhi csata");

    prjcs = admin.list<DAOProject>  ();
    tasks = admin.list<DAOTask>     ();
    empls = admin.list<DAOEmployee> ();
    ddlns = admin.list<Deadline> ();

    for (auto i: prjcs)
        std::cout<<i.to_string ()<<std::endl;
    for (auto i: tasks)
        std::cout<<i.to_string ()<<std::endl;
    for (auto i: empls)
        std::cout<<i.to_string ()<<std::endl;
    for (auto i: ddlns)
        std::cout<<i.to_string ()<<std::endl;
    return 0;
} 
