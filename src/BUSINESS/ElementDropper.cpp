#include "ElementDropper.hpp"

void ElementDropper::drop_project  (const std::string& p_name)
{
    const DAOProject& dao_project = m_df.get<DAOProject> ();
    auto projects = dao_project.getAll ();
    for (auto i: projects)
        if (i.get_name () == p_name)
            dao_project.deleteFromDB (&i);
    projects.erase( std::remove_if( projects.begin(), projects.end(), [&](auto& i){return i.get_name () == p_name;} ), projects.end() );
}

void ElementDropper::drop_task     (const std::string& p_name)
{
    DAOTask dao = m_df.get<DAOTask> ();
    auto tasks = dao.getAll ();
    
     for (auto i: tasks)
        if (i.get_name () == p_name)
            dao.deleteFromDB (&i);
    tasks.erase( std::remove_if( tasks.begin(), tasks.end(), [&](auto& i){return i.get_name () == p_name;} ), tasks.end() );
}

void ElementDropper::drop_employee (const std::string& p_name)
{
    DAOTask dao = m_df.get<DAOTask> ();
    auto empls = dao.getAll ();
    
    for (auto i: empls)
        if (i.get_name () == p_name)
            dao.deleteFromDB (&i);
    empls.erase( std::remove_if( empls.begin(), empls.end(), [&](auto& i){return i.get_name () == p_name;} ), empls.end() );
}


