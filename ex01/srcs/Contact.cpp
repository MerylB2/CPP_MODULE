#include "Contact.hpp"

Contact::Contact() {
    
}

Contact::~Contact() {
    
}

void Contact::setFirstName(const std::string& name) {
    firstname = name;
}

void Contact::setLastName(const std::string& name) {
    lastname = name;
}

void Contact::setNickName(const std::string& name) {
    nickname =  name;
}

void Contact::setPhoneNumber(const std::string& num) {
    phoneNumber = num;
}

void Contact::setDarkestSecret(const std::string& secret) {
    darkestSecret = secret;
}

std::string Contact::getFirstName() const {
    return firstname;
}

std::string Contact::getLastName() const {
    return lastname;
}

std::string Contact::getNickName() const {
    return nickname;
}

std::string Contact::getPhoneNumber() const {
    return phoneNumber;
}

std::string Contact::getDarkestSecret() const {
    return darkestSecret;
}

bool Contact::isEmpty() const {
    return firstname.empty();
}
