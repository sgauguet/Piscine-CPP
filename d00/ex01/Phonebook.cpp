
#include "Phonebook.hpp"
#include "Contact.hpp"

Phonebook::Phonebook( void ) {
	std::cout << "----------- PHONEBOOK -----------" << std::endl;
	this->_contact_saved = 0;
	return;
}

Command Phonebook::checkCommand(std::string input) const {
	if (input.compare("ADD") == 0)
		return ADD;
	else if (input.compare("SEARCH") == 0)
		return SEARCH;
	else if (input.compare("EXIT") == 0)
		return EXIT;
	return INVALID;
}

void Phonebook::addContact  (void ) {

	std::string	input;
	int 		index;
	Contact 	*new_contact;

	index = this->_contact_saved;

	if (index >= 8) {
		std::cout << "SORRY, PHONEBOOK IS FULL. YOU CAN'T ADD NEW CONTACTS ANYMORE." << std::endl;
		return;
	}

	new_contact = &(this->contacts[index]);
	std::cout << "First name:" << std::endl;
	std::getline (std::cin, input);
	new_contact->setFirstName (input);
	std::cout << "Last name:" << std::endl;
	std::getline (std::cin, input);
	new_contact->setLastName (input);
	std::cout << "nickname:" << std::endl;
	std::getline (std::cin, input);
	new_contact->setNickName (input);
	std::cout << "Login:" << std::endl;
	std::getline (std::cin, input);
	new_contact->setLogin (input);
	std::cout << "Postal adress:" << std::endl;
	std::getline (std::cin, input);
	new_contact->setPostalAdress (input);
	std::cout << "Email adress:" << std::endl;
	std::getline (std::cin, input);
	new_contact->setEmailAdress (input);
	std::cout << "Phone number:" << std::endl;
	std::getline (std::cin, input);
	new_contact->setPhoneNumber (input);
	std::cout << "Birthday date:" << std::endl;
	std::getline (std::cin, input);
	new_contact->setBirthdayDate (input);
	std::cout << "Favorite meal:" << std::endl;
	std::getline (std::cin, input);
	new_contact->setFavoriteMeal (input);
	std::cout << "Underwear color:" << std::endl;
	std::getline (std::cin, input);
	new_contact->setUnderwearColor (input);
	std::cout << "Darkest secret:" << std::endl;
	std::getline (std::cin, input);
	new_contact->setDarkestSecret (input);

	std::cout << "CONTACT HAS BEEN SUCCESSFULLY ADDED." << std::endl;
	this->_contact_saved = this->_contact_saved + 1;
	return;
}

void Phonebook::searchContact  (void ) {
	unsigned int	input;
	int 			index;

	index = 0;
	if (!this->_contact_saved) {
		std::cout << "PHONEBOOK IS EMPTY." << std::endl;
		return;
	}
	std::cout << "----------- CONTACT LIST -----------" << std::endl;
	while (index < this->_contact_saved) {
		std::cout << std::setw(10) << std::setiosflags (std::ios::right) << index + 1 << "|";
		std::cout << std::setw(10) << std::setiosflags (std::ios::right) << this->contacts[index].getFirstName(1) << "|";
		std::cout << std::setw(10) << std::setiosflags (std::ios::right) << this->contacts[index].getLastName(1) << "|";
		std::cout << std::setw(10) << std::setiosflags (std::ios::right) << this->contacts[index].getNickName(1) << std::endl;
		index++;
	}
	std::cout << "CHOOSE CONTACT INDEX: " << std::endl;
	std::cin >> input;
	if (std::cin.good()){
		index = input - 1;
		if (index >= 0 && index < this->_contact_saved) {
			std::cout << "----------- CONTACT DETAILS -----------" << std::endl;
			std::cout << "First name: " << this->contacts[index].getFirstName() << std::endl;
			std::cout << "Last name: " << this->contacts[index].getLastName() << std::endl;
			std::cout << "nickname: " << this->contacts[index].getNickName() << std::endl;
			std::cout << "Login: " << this->contacts[index].getLogin() << std::endl;
			std::cout << "Postal Adress: " << this->contacts[index].getPostalAdress() << std::endl;
			std::cout << "Email Adress: " << this->contacts[index].getEmailAdress() << std::endl;
			std::cout << "Phone Number: " << this->contacts[index].getPhoneNumber() << std::endl;
			std::cout << "Birthday Date: " << this->contacts[index].getBirthdayDate() << std::endl;
			std::cout << "Favorite Meal: " << this->contacts[index].getFavoriteMeal() << std::endl;
			std::cout << "Underwear color: " << this->contacts[index].getUnderwearColor() << std::endl;
			std::cout << "Darkest secret: " << this->contacts[index].getDarkestSecret() << std::endl;
			return;
		}
	}
	std::cin.clear();
    std::cin.ignore(32767,'\n');
	std::cout << "INVALID INDEX." << std::endl;
	return;
}


void Phonebook::exit (void ) {
	std::exit(0);
}
