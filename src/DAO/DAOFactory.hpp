#ifndef DAO_FACTORY
#define DAO_FACTORY

#include <type_traits>
#include "DAOInterface.hpp"
#include <sqlite3.h>
class DAOFactory
{
public:
    DAOFactory();
    DAOFactory(DAOFactory &&) = default;
    DAOFactory(const DAOFactory &) = default;
    DAOFactory &operator=(DAOFactory &&) = default;
    DAOFactory &operator=(const DAOFactory &) = default;
    ~DAOFactory();

    template<typename DAOType>
    DAOType* getDAO (){
        static_assert(std::is_base_of<DAOInterface, DAOType>::value, "Template argument is not a DAO");

        return new DAOType ();
    }

    void Initialize () {
        sqlite3* dbHdl;
        int Err = 0;
        Err = sqlite3_open ("../DATA/DB.sqlite3", &dbHdl);
    }

private:
    
};

DAOFactory::DAOFactory()
{
}

DAOFactory::~DAOFactory()
{
}
#endif // !DAO_FACTORY