#ifndef DAO_FACTORY
#define DAO_FACTORY

#include <type_traits>
#include <sqlite3.h>

#include "DAOInterface.hpp"

class DAOFactory
{
    sqlite3* hdl = query::hdl;
public:
    DAOFactory ();
    DAOFactory (DAOFactory &&)                 = default;
    DAOFactory (const DAOFactory &)            = default;
    DAOFactory &operator= (DAOFactory &&)      = default;
    DAOFactory &operator= (const DAOFactory &) = default;
    ~DAOFactory() = default;

    template<typename DAOType>
    inline DAOType get () const {
        static_assert(std::is_base_of<DAOInterface, DAOType>::value, "Template argument is not a DAO");
        return DAOType ();
    }
    
};

#endif // !DAO_FACTORY
