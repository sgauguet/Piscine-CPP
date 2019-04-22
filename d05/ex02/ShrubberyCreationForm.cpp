#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : _name("n°666"), _grade_sign(150), _grade_exec(150), _signed(0) {
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string name, int sign, int exec) : _name(name), _grade_sign(sign), _grade_exec(exec), _signed(0)  {
	if (sign < 1 || exec < 1)
		throw ShrubberyCreationForm::GradeTooHighException();
	else if (sign > 150 || exec > 150)
		throw ShrubberyCreationForm::GradeTooLowException();
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & copy) : _name(copy.getName()), _grade_sign(copy.getGradeSign()), _grade_exec(copy.getGradeExec()) {
	*this = copy;
	return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
	return ;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & b) {
	this->_signed = b._signed;
	return *this;
}

std::string const ShrubberyCreationForm::getName(void) const {
	return this->_name;
}

int ShrubberyCreationForm::getGradeSign(void) const {
	return this->_grade_sign;
}

int ShrubberyCreationForm::getGradeExec(void) const {
	return this->_grade_exec;
}

bool ShrubberyCreationForm::getSigned(void) const {
	return this->_signed;
}

void ShrubberyCreationForm::beSigned(Bureaucrat & a) {
	if (a.getGrade() > this->getGradeSign()) {
		throw ShrubberyCreationForm::GradeTooLowException();
		return ;
	}
	this->_signed = true;
}

std::ostream & operator<<(std::ostream & o, ShrubberyCreationForm const & rhs) {
	o << "ShrubberyCreationForm " << rhs.getName() << ", grade required to sign " << rhs.getGradeSign() << ", grade required to exec " << rhs.getGradeExec() << ", status : " << rhs.getSigned() << "." << std::endl;
	return o;
}

const char * ShrubberyCreationForm::GradeTooHighException::what(void) const throw() {
	return ("ShrubberyCreationForm grade too high.");
}

const char * ShrubberyCreationForm::GradeTooLowException::what(void) const throw() {
	return ("ShrubberyCreationForm grade too low.");
}
