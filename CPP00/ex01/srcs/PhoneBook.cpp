#include <PhoneBook.hpp>

PhoneBook::PhoneBook() : contactCount(0), odlIndex(0) {

}

PhoneBook::~PhoneBook() {

}

// Truncate string to 10 characters and add a dot if needed
std::string PhoneBook::truncateString(const std::string& str) const {
	if(str.length() > 10) {
		return str.substr(0, 9) + ".";
	}
	return str;
}

// Get non-empty input from user with validation loop
std::string PhoneBook::getNonEmptyInput(const std::string& prompt) const {
	std::string input;

	while (true) {
		std::cout << prompt;
		if (!std::getline(std::cin, input)) {
			std::cout << std::endl;
			exit(0);
		}

		if (!input.empty()) {
			return input;
		}
		std::cout << "\033[1;4;31m" << "This field cannot be empty. Please try again." << "\033[0m"  << std::endl;
	}
}

// Validate that phone number contains only digits
bool PhoneBook::isValidPhoneNumber(const std::string& number) const {
	if (number.empty()) {
		return false;
	}
	
	for (size_t i = 0; i < number.length(); i++) {
		if (!std::isdigit(number[i])) {
			return false;
		}
	}
	return true;
}

// Get phone number with validation (only digits allowed)
std::string PhoneBook::getPhoneNumber() const {
	std::string number;
	
	while (true) {
		number = getNonEmptyInput("Phone number: ");
		
		if (isValidPhoneNumber(number)) {
			return number;
		}
		std::cout << "\033[1;4;31m" << "Phone number must contain only digits. Please try again." << "\033[0m"  << std::endl;
	}
}

// Add a new contact to the phonebook
// If the phonebook is full (8 contacts), replace the oldest one
void PhoneBook::addContact() {
	Contact newContact;

	std::cout << std::endl;
	newContact.setFirstName(getNonEmptyInput("Firstname : "));
	newContact.setLastName(getNonEmptyInput("Lastname : "));
	newContact.setNickName(getNonEmptyInput("Nickname : "));
	newContact.setPhoneNumber(getPhoneNumber());
	newContact.setDarkestSecret(getNonEmptyInput("Darkest Secret : "));

	if (contactCount < 8) {
		contacts[contactCount] = newContact;
		contactCount++;
	}
	else {
		contacts[odlIndex] = newContact;
		odlIndex = (odlIndex + 1) % 8;
	}

	std::cout << "\033[1;32m" << "Contact successfully added!" << "\033[0m" << std::endl << std::endl;
}

void PhoneBook::displayContactList() const {
	std::cout << std::endl;
	std::cout << std::setw(10) << std::right << "Index" << "|";
	std::cout << std::setw(10) << std::right << "Firstname" << "|";
	std::cout << std::setw(10) << std::right << "Lastname" << "|";
	std::cout << std::setw(10) << std::right << "Nickname" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;

	for (int i = 0; i < contactCount; i++) {
		std::cout << std::setw(10) << std::right << i << "|";
		std::cout << std::setw(10) << std::right << truncateString(contacts[i].getFirstName()) << "|";
		std::cout << std::setw(10) << std::right << truncateString(contacts[i].getLastName()) << "|";
		std::cout << std::setw(10) << std::right << truncateString(contacts[i].getNickName()) << std::endl;
	}
	std::cout << std::endl;
}

void PhoneBook::displayContact(int index) const {
    std::cout << std::endl;
    std::cout << "\033[1;95mFirst name: \033[0m" << contacts[index].getFirstName() << std::endl;
    std::cout << "\033[1;95mLast name: \033[0m" << contacts[index].getLastName() << std::endl;
    std::cout << "\033[1;95mNickname: \033[0m" << contacts[index].getNickName() << std::endl;
    std::cout << "\033[1;95mPhone number: \033[0m" << contacts[index].getPhoneNumber() << std::endl;
    std::cout << "\033[1;95mDarkest secret: \033[0m" << contacts[index].getDarkestSecret() << std::endl;
    std::cout << std::endl;
}

void PhoneBook::searchContact() const {
	if (contactCount == 0) {
		std::cout << "\033[1;31m" << "The phonebook is empty." << "\033[0m" << std::endl;
		return;
	}
	
	displayContactList();

	
	while (true) {
		std::string input;
		std::cout << "\033[96m" << "Enter the index of the contact to display (0-" << (contactCount - 1) << ") or EXIT to quit: " << "\033[0m";

		if (!std::getline(std::cin, input)) {
			std::cout << std::endl;
			exit(0);
		}

		// Check if user wants to exit
        if (input == "EXIT") {
            std::cout << "\033[1;93m" << "You're not anymore in the phonebook !"  << "\033[0m" << std::endl;
            exit(0);
        }

		std::stringstream ss(input);
		int index;

		if (!(ss >> index) || !(ss.eof())) {
			std::cout << "\033[31m" << "Invalid index. Please enter a number." << "\033[0m" << std::endl << std::endl;
			continue;
		}

		if (index < 0 || index >= contactCount) {
			std::cout << "\033[93m" << "Index out of range. Please enter an index between 0 and " << (contactCount - 1) << "." << "\033[0m" << std::endl << std::endl;
			continue;
		}

		displayContact(index);
		break;
	}
}
