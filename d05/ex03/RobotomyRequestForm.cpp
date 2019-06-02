#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : Form("RobotomyRequestForm", 72, 45) {
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("RobotomyRequestForm", 72, 45) {
	this->setTarget(target);
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & copy) : Form(copy) {
	*this = copy;
	return ;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
	return ;
}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & b) {
	Form::operator=(b);
	return *this;
}

void RobotomyRequestForm::executeAction(void) const {
	if (std::rand() % 2 == 0)
		std::cout << this->getTarget() << " has been robotomized successfully." << std::endl;
	else
		std::cout << this->getTarget() << " has not been robotomized." << std::endl;
	return ;
}
