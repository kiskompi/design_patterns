#ifndef ProjectFACTORY_HPP
#define ProjectFACTORY_HPP

#include "../TRANSFER/Project.hpp"
#include "../DAO/DAO.hpp"

class ProjectFactory: public ElementFactory
{
    DAOProject m_dao_empl = DAOFactory ().get<DAOProject> ();

public:
	ProjectFactory () {}

    virtual Project make_element (
        const std::string& p_name,
        const std::string& p_desc) const 
    {
        Project empl = Project (p_name, p_desc);

        m_dao_empl.add (&empl);
        return empl;
    }

};
    


#endif //ProjectFACTORY_HPP
