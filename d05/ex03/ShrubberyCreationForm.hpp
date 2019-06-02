#ifndef SHRUBBERYCREATIONFORM_H
#define SHRUBBERYCREATIONFORM_H

#include <iostream>
#include <exception>
#include <fstream>
#include "Form.hpp"

class Form;

class ShrubberyCreationForm : public Form {

public:

	ShrubberyCreationForm(void);
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(ShrubberyCreationForm const & copy);
	~ShrubberyCreationForm(void);
	ShrubberyCreationForm & operator=(ShrubberyCreationForm const & b);

	void executeAction(void) const;

private:
	static std::string const _content;
};

#endif
