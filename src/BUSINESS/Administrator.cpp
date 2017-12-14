#include "Administrator.hpp"

Administrator::Administrator ()
{
    
}

Administrator& Administrator::make_admin ()
{
    static Administrator m_instance = Administrator ();
    return m_instance;
}

short Administrator::assign_task (const std::string& taskStr, const std::string& emplStr) {
    std::vector<Task> tasks = m_lister.list_tasks ();
    std::vector<Employee> empls = m_lister.list_employees ();
    Task*     task = nullptr;
    Employee* empl = nullptr;

    for (auto& task_iter: tasks) {
        if (task_iter.get_name() == taskStr){
            task = &task_iter;
            break;
        }
    }
    for (auto& i: empls) {
        if (i.get_name() == emplStr){
            empl = &i;
            break;
        }
    }
    if (task == nullptr || empl == nullptr)
        return -1;

    DAOTask dt = DAOTask();
    dt.create_table_tasks_employees ();
    dt.assign (*empl, *task);
    return 0;
}


