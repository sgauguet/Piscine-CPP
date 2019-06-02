#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void) {
	Bureaucrat bureaucrat1 = Bureaucrat("Super Boss", 2);
	Bureaucrat bureaucrat2 = Bureaucrat("Foot soldier", 147);
	Form form1 = Form("n°1", 14, 12);
	Form form2 = Form(form1);
	Form form3 = Form("n°2", 145, 110);
	Form form4 = form3;
	Form form5;

	std::cout << bureaucrat1;
	std::cout << bureaucrat2;
	std::cout << form1;
	std::cout << "---------- Test - Copy constructor ----------" << std::endl;
	std::cout << form2;
	std::cout << "---------- Test - assignment ----------" << std::endl;
	std::cout << form3;
	std::cout << form4;
	std::cout << "---------- Test - Default constructor ----------" << std::endl;
	std::cout << form5;
	try {
		std::cout << "---------- Test - create form with grade too high ----------" << std::endl;
		form5 = Form("error", -5, 150);
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << "---------- Test - beSigned function - ok ----------" << std::endl;
		std::cout << "Signature of form n°1 by " << bureaucrat1.getName() << std::endl;
		form1.beSigned(bureaucrat1);
		std::cout << form1;
		std::cout << "---------- Test - beSigned function - not ok (grade too low) ----------" << std::endl;
		std::cout << "Signature of form n°1 by " << bureaucrat2.getName() << std::endl;
		form2.beSigned(bureaucrat2);
		std::cout << form2;
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << "---------- Test - signForm - ok ----------" << std::endl;
		bureaucrat1.signForm(form3);
		std::cout << form3;
		std::cout << "---------- Test - signForm - not ok (grade too low) ----------" << std::endl;
		bureaucrat2.signForm(form4);
		std::cout << form4;
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "---------- Test - beSigned - already signed ----------" << std::endl;
	form1.beSigned(bureaucrat1);
	std::cout << "---------- Test - signForm - already signed ----------" << std::endl;
	bureaucrat1.signForm(form3);
}
