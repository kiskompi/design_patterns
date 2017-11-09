#include "../UI/CommandAdapter.hpp"

int main () {
    CommandAdapter cad = CommandAdapter();
    std::string v;
    while (true)
    {
        cad.ask(v);
        cad.execute_dummy(v);
    }
}