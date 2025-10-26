#include "PhoneBook.hpp"

int main()
{
    PhoneBook PhoneBook;
    std::string cmd;

    std::cout << std::endl;
    std::cout << "\033[1;37;42m"  << "===***  WELCOME TO THE PHONEBOOK ***===" << "\033[0m" <<std::endl;
    std::cout << "\033[96m" << "Available commands: ADD, SEARCH, EXIT" << "\033[0m" << std::endl << std::endl;
    std::cout << "* - ADD: Add a new contact with validation" << std::endl;
    std::cout << "* - SEARCH: Display contacts and select one to view details" << std::endl;
    std::cout << "* - EXIT: Quit the program" << std::endl << std::endl;

    while (true)
    {
        std::cout << "\033[1m" << "Enter a command :" << "\033[0m" ;

        if (!std::getline(std::cin, cmd)) {
            std::cout << std::endl;
            break;
        }

        if (cmd == "ADD") {
            PhoneBook.addContact();
        }
        else if (cmd == "SEARCH") {
            PhoneBook.searchContact();
        }
        else if (cmd == "EXIT") {
            std::cout << "\033[1;93m" << "You're not anymore in the phonebook!"  << "\033[0m" << std::endl;
            break;
        }
        else if (!cmd.empty()) {
            std::cout << "\033[31m" << "Unknown command." << "\033[0m" << std::endl;
            std::cout << "\033[96m" << "Available commands: ADD, SEARCH, EXIT" << "\033[0m" << std::endl << std::endl;
        }
    }
    return 0;
}
