#ifndef INTERN_H
#define INTERN_H

#include <iostream>
#include <exception>
#include <fstream>
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Form;

class Intern {

public:

	Intern(void);
	Intern(Intern const & copy);
	~Intern(void);
	Intern & operator=(Intern const & b);

	Form * makeForm(std::string formName, std::string formTarget) const ;

private:
	Form * _newRobotomyRequestForm(std::string formTarget) const;
	Form * _newShrubberyCreationForm(std::string formTarget) const;
	Form * _newPresidentialPardonForm(std::string formTarget) const;

};

#endif
