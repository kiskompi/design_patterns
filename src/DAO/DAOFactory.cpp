#include "DAOFactory.hpp"

namespace query {
	sqlite3* hdl = nullptr;
}
DAOFactory::DAOFactory()
{
    if (hdl == nullptr)
        sqlite3_open ("test.db", &hdl);    
}

