#include "Bureaucrat.hpp"

int main(void) {
	Bureaucrat hermes = Bureaucrat("Hermes Conrad", 37);
	Bureaucrat bob = Bureaucrat("Bobby Bobson", 123);
	Bureaucrat copy = Bureaucrat(hermes);
	Bureaucrat x;
	int i = 0;

	std::cout << hermes;
	std::cout << bob;
	std::cout << copy;
	std::cout << x;
	try {
		hermes.incrementGrade();
		std::cout << "test increment : " << hermes;
		hermes.decrementGrade();
		std::cout << "test decrement: " << hermes;
		while (i < 37) {
			hermes.incrementGrade();
			std::cout << hermes;
			i++;
		}
	}
	catch (Bureaucrat::GradeTooHighException & e){
		std::cout << "Exception 1 catched : " << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException & e){
		std::cout << "Exception 2 catched : " << e.what() << std::endl;
	}
	catch (std::exception & e){
		std::cout << "Exception 3 catched : " << e.what() << std::endl;
	}
	try {
		Bureaucrat superbob = Bureaucrat("Super Bobby", 151);
	}
	catch (std::exception & e){
		std::cout << "Exception 3 catched : " << e.what() << std::endl;
	}
}