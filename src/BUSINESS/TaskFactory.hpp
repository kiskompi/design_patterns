#ifndef TASKFACTORY_HPP
#define TASKFACTORY_HPP

#include "../TRANSFER/Task.hpp"
#include "../DAO/DAO.hpp"

class TaskFactory: public ElementFactory
{
    DAOTask m_dao_empl = DAOFactory().get<DAOTask> ();

public:
	TaskFactory () {}

    virtual Task make_element ( 
        const std::string& p_name, 
        const std::string& p_type,  
        const std::string& p_priority, 
        const std::string& p_deadline, 
        const std::string& p_Task, 
        const std::string& p_desc) const {
        Task empl = Task (p_name, p_type, p_priority, p_deadline, p_Task, p_desc);
        m_dao_empl.add (&empl);
        return empl;
    }

	
};
    


#endif //TASKFACTORY_HPP
