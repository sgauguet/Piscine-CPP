#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include "Form.hpp"

int main(void) {
	Intern someRandomIntern;
	Form* rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	std::cout << "Form " << rrf->getName() << " has target " << rrf->getTarget() << std::endl;
	delete rrf;
	rrf = someRandomIntern.makeForm("shrubbery creation", "Home");
	std::cout << "Form " << rrf->getName() << " has target " << rrf->getTarget() << std::endl;
	delete rrf;
	rrf = someRandomIntern.makeForm("presidential pardon", "Bob");
	std::cout << "Form " << rrf->getName() << " has target " << rrf->getTarget() << std::endl;
	delete rrf;
	rrf = someRandomIntern.makeForm("unknown", "Bob");
}
