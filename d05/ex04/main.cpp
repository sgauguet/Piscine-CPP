#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include "Form.hpp"
#include "OfficeBlock.hpp"

int main(void) {
	Intern idiotOne;
	Bureaucrat hermes = Bureaucrat("Hermes Conrad", 37);
	Bureaucrat bob = Bureaucrat("Bobby Bobson", 123);
	OfficeBlock ob1(idiotOne, hermes, bob);
	OfficeBlock ob2;
	ob2.setIntern(idiotOne);
	ob2.setSigner(bob);
	//ob2.setExecutor(hermes);
	try
	{
		ob1.doBureaucracy("shrubbery creation", "Pigley");
		ob2.doBureaucracy("presidential pardon", "Criminal");
	}
	catch (OfficeBlock::formException & e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (OfficeBlock::paramException & e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		ob1.doBureaucracy("bdshfngfdnw", "error");
	}
	catch (OfficeBlock::formException & e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
}
