#include <iostream>
#include <string>

inline std::string read_command () {
    std::string command = "";
    std::cin >> command;
    return command;
}

int main () 
{
    while (true) {
        std::cout<<"Welcome!\n";
        std::cout<<"To list commands type: help, to quit: Quit\n";
        std::cout<<"Have fun...\n";
        const std::string command = read_command ();
    }
}