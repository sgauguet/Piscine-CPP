#include "Form.hpp"

Form::Form(void) : _name("n°666"), _grade_sign(150), _grade_exec(150), _signed(0) {
	return ;
}

Form::Form(std::string name, int sign, int exec) : _name(name), _grade_sign(sign), _grade_exec(exec), _signed(0)  {
	if (sign < 1 || exec < 1)
		throw Form::GradeTooHighException();
	else if (sign > 150 || exec > 150)
		throw Form::GradeTooLowException();
	return ;
}

Form::Form(Form const & copy) : _name(copy.getName()), _grade_sign(copy.getGradeSign()), _grade_exec(copy.getGradeExec()) {
	*this = copy;
	return ;
}

Form::~Form(void) {
	return ;
}

Form & Form::operator=(Form const & b) {
	this->_signed = b._signed;
	return *this;
}

std::string const Form::getName(void) const {
	return this->_name;
}

int Form::getGradeSign(void) const {
	return this->_grade_sign;
}

int Form::getGradeExec(void) const {
	return this->_grade_exec;
}

bool Form::getSigned(void) const {
	return this->_signed;
}

void Form::beSigned(Bureaucrat & a) {
	if (a.getGrade() > this->getGradeSign()) {
		throw Form::GradeTooLowException();
		return ;
	}
	this->_signed = true;
}

std::ostream & operator<<(std::ostream & o, Form const & rhs) {
	o << "Form " << rhs.getName() << " requires grade "  << rhs.getGradeSign() << " to be signed " << ", and grade " << rhs.getGradeExec() << " to be executed."  << " Current status : " << rhs.getSigned() << "." << std::endl;
	return o;
}

/* GradeTooHighException */

Form::GradeTooHighException::GradeTooHighException(void) {
	return ;
}

Form::GradeTooHighException::GradeTooHighException(GradeTooHighException const & copy) {
	*this = copy;
	return ;
}

Form::GradeTooHighException::~GradeTooHighException(void) throw() {
	return ;
}

Form::GradeTooHighException & Form::GradeTooHighException::operator=(GradeTooHighException const &) {
	return *this;
}

const char * Form::GradeTooHighException::what(void) const throw() {
	return ("Grade too high.");
}

/* GradeTooLowException */

Form::GradeTooLowException::GradeTooLowException(void) {
	return ;
}

Form::GradeTooLowException::GradeTooLowException(GradeTooLowException const & copy) {
	*this = copy;
	return ;
}

Form::GradeTooLowException::~GradeTooLowException(void) throw() {
	return ;
}

Form::GradeTooLowException & Form::GradeTooLowException::operator=(GradeTooLowException const &) {
	return *this;
}

const char * Form::GradeTooLowException::what(void) const throw() {
	return ("Grade too low.");
}
