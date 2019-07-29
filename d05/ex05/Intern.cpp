#include "Intern.hpp"

Intern::Intern(void) {
	return ;
}

Intern::Intern(Intern const & copy) {
	*this = copy;
	return ;
}

Intern::~Intern(void) {
	return ;
}

Intern & Intern::operator=(Intern const &) {
	return *this;
}

Form * Intern::makeForm(std::string formName, std::string formTarget) const {
	Form * (Intern::*f[3])(std::string formTarget) const;
	Form * result;
	std::string forms[3] = { "robotomy request", "shrubbery creation", "presidential pardon" };
	int i;

	f[0] = &Intern::_newRobotomyRequestForm;
	f[1] = &Intern::_newShrubberyCreationForm;
	f[2] = &Intern::_newPresidentialPardonForm;
	i = 0;
	while (i < 3) {
		if (forms[i] == formName) {
			result = (this->*f[i])(formTarget);
			std::cout << "Intern creates " << result->getName() << " targeted on " << formTarget << "." << std::endl;
			return result;
		}
		i++;
	}
	std::cout << "Requested form " << formName << " is not known." << std::endl;
	return NULL;
}

Form * Intern::_newRobotomyRequestForm(std::string formTarget) const {
	return new RobotomyRequestForm(formTarget);
}
Form * Intern::_newShrubberyCreationForm(std::string formTarget) const {
	return new ShrubberyCreationForm(formTarget);
}
Form * Intern::_newPresidentialPardonForm(std::string formTarget) const {
	return new PresidentialPardonForm(formTarget);
}
