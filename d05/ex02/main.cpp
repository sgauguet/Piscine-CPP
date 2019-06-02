#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Form.hpp"

int main(void) {
	Bureaucrat n1("Conseiller-maître", 5);
	Bureaucrat n2("Secrétaire", 145);
	ShrubberyCreationForm a("Home");
	ShrubberyCreationForm a2(a);
	RobotomyRequestForm b("Rambo");
	RobotomyRequestForm b2;
	b2 = b;
	PresidentialPardonForm c("Bob");
	PresidentialPardonForm c2(c);
	std::cout << "---------- Test - execute ----------" << std::endl;
	n1.signForm(a2);
	n1.executeForm(a2);
	n1.signForm(b2);
	n1.executeForm(b2);
	n1.signForm(c2);
	n1.executeForm(c2);
	std::cout << "---------- Test - not signed exception ----------" << std::endl;
	n1.executeForm(a);
	std::cout << "---------- Test - grade too low exception ----------" << std::endl;
	n2.executeForm(a2);
}
