#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>
#include <iomanip> 
#include <cstdlib>
#include <string>
#include "Contact.hpp"

enum Command
{
    ADD,
    SEARCH,
    EXIT, 
    INVALID
};
 
class Phonebook {

public: 
	Phonebook(void);
	Command checkCommand(std::string input) const;
	void addContact(void);
	void searchContact(void);
	void exit(void);

private:
	Contact contacts[8];
	int _contact_saved;
};
 
#endif
