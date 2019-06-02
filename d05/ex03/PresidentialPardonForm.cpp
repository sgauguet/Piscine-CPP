#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : Form("PresidentialPardonForm", 25, 5) {
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("PresidentialPardonForm", 25, 5) {
	this->setTarget(target);
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & copy) : Form(copy) {
	*this = copy;
	return ;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
	return ;
}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const & b) {
	Form::operator=(b);
	return *this;
}

void PresidentialPardonForm::executeAction(void) const {
	std::cout << this->getTarget() << " has been pardoned by Zafod Beeblebrox." << std::endl;
	return ;
}
