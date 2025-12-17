#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <sstream>
#include <cctype>
#include "Contact.hpp"

class PhoneBook {
    private:
        Contact contacts[8];
        int contactCount;
        int odlIndex;

        std::string truncateString(const std::string& str) const;
        void displayContactList() const;
        void displayContact(int index) const;
        std::string getNonEmptyInput(const std::string& prompt) const;
        bool isValidPhoneNumber(const std::string& number) const;
        std::string getPhoneNumber() const;
    
    public:
        PhoneBook();
        ~PhoneBook();

        void addContact();
        void searchContact() const;
};

#endif