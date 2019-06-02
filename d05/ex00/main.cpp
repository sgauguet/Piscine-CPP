#include "Bureaucrat.hpp"

int main(void) {
	Bureaucrat hermes = Bureaucrat("Hermes Conrad", 37);
	Bureaucrat bob = Bureaucrat("Bobby Bobson", 123);
	Bureaucrat copy = Bureaucrat(hermes);
	Bureaucrat x;
	int i = 0;

	std::cout << hermes;
	std::cout << bob;
	std::cout << "---------- Test - Copy constructor ----------" << std::endl;
	std::cout << copy;
	std::cout << "---------- Test - Default constructor ----------" << std::endl;
	std::cout << x;
	try {
		std::cout << "---------- Test - increment ----------" << std::endl;
		hermes.incrementGrade();
		std::cout << hermes;
		std::cout << "---------- Test - decrement ----------" << std::endl;
		hermes.decrementGrade();
		std::cout << hermes;
		std::cout << "---------- Test - too high exception ----------" << std::endl;
		while (i < 100) {
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
	std::cout << "---------- Test - too low exception ----------" << std::endl;
	try {
		Bureaucrat superbob = Bureaucrat("Super Bobby", 151);
	}
	catch (std::exception & e){
		std::cout << "Exception catched : " << e.what() << std::endl;
	}
}
