#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include "Form.hpp"

int main(void) {
	Intern idiotOne;
	Bureaucrat hermes = Bureaucrat("Hermes Conrad", 37);
	Bureaucrat bob = Bureaucrat("Bobby Bobson", 123);
	OfficeBlock ob;
	ob.setIntern(idiotOne);
	ob.setSigner(bob);
	ob.setExecutor(hermes);
	try
	{
	ob.doBureaucracy("mutant pig termination", "Pigley");
	}
	catch (Some::SpecificException & e)
	{
	/* specific known error happens, say something */
	}
	catch (std::exception & e)
	{
	/* oh god, unknown error, what to do ?! */
	}
}
