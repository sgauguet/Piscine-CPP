#ifndef PRESIDENTIALPARDONFORM_H
#define PRESIDENTIALPARDONFORM_H

#include <iostream>
#include <exception>
#include "Form.hpp"

class Form;

class PresidentialPardonForm : public Form {

public:

	PresidentialPardonForm(void);
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(PresidentialPardonForm const & copy);
	~PresidentialPardonForm(void);
	PresidentialPardonForm & operator=(PresidentialPardonForm const & b);

	void executeAction(void) const;

};

#endif
