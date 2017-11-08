#include "../BUSINESS/Administrator.hpp"
# include <iostream>
int main () {
    Administrator& admin = Administrator::make_admin ();

    admin.make_employee ("Aladar", "Adress", "amail", "phone");
    admin.make_task     ("Varmodell", "3D modellezes", "10", "2012-01-01", "Az egri var 3D modelljenek kidolgozasa.", "Egri csata ");
    admin.make_project  ("Muhi csata", "Janos");
    
    std::vector<Project>  prjcs = admin.list_projects  ();
    std::vector<Task>     tasks = admin.list_tasks     ();
    std::vector<Employee> empls = admin.list_employees ();
    std::vector<Deadline> ddlns = admin.list_deadlines ();

    for (auto& i: prjcs)
        std::cout<<i.to_string ()<<std::endl;
    for (auto& i: tasks)
        std::cout<<i.to_string ()<<std::endl;
    for (auto& i: empls)
        std::cout<<i.to_string ()<<std::endl;
    for (auto& i: ddlns)
        std::cout<<i.to_string ()<<std::endl;

    admin.drop_employee ("Aladar");
    admin.drop_task     ("Varmodell");
    admin.drop_project  ("Muhi csata");

    prjcs = admin.list_projects  ();
    tasks = admin.list_tasks     ();
    empls = admin.list_employees ();
    ddlns = admin.list_deadlines ();

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