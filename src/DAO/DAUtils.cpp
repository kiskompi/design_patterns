#include "../DAO/DAOTask.hpp";
#include "../DAO/DAOEmployee.hpp";
#include "../DAO/Query.hpp";

namespace query {
    void assign (sqlite3* hdl, Task& t, Employee& e) {
        std::string query = "INSERT INTO TASKS TASKS_EMPLOYEES(" + e.to_string () + ", " + t.to_string () + ");";
        int err = sqlite3_exec (hdl, query.c_str (), NULL, NULL, NULL);
    }

    void create_table_tasks_employees (sqlite3* hdl) {
        int err = sqlite3_exec (hdl, query.c_str (), NULL, NULL, NULL);
    }
}