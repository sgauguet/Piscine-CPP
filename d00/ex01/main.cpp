
#include "Phonebook.hpp"

int main() {
	std::string input;
	Phonebook phonebook;
	Command valid_commands;
	while (1) {
		std::getline (std::cin, input);
		valid_commands = phonebook.checkCommand(input);
		switch(valid_commands)
		{
   			case ADD : phonebook.addContact();   break;
    		case SEARCH: phonebook.searchContact(); break;
    		case EXIT : phonebook.exit();  break;
    		case INVALID : break;
		}
	}
	return 0;
}