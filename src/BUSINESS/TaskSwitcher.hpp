class TaskSwitcher {
    short switch_tasks (std::string& t1str, std::string& t2str);
 };

 
short Administrator::switch_tasks (std::string& t1str, std::string& t2str) {
    std::vector<Task> vec = list_tasks ();
    Task* t1 = nullptr;
    Task* t2 = nullptr;
    short s = 0;
    for (auto& i: vec) {
        if (i.get_name() == t1str){
            t1 = &i;
            ++s;
        }
        if (i.get_name() == t2str){
            t2 = &i;
            ++s;
        }
        if (s == 2)
            break;
    }
    if (t1 == nullptr || t2 == nullptr)
        return -1;
    
    Employee tmp_empl = t1->get_employee ();
    m_dao_task.assign ( t2->get_employee (), *t1);
    m_dao_task.assign (tmp_empl, *t2);

    return 0;
}