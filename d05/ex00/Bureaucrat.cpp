#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("Mr Nobody"), _grade(150) {
	return ;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade) {
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	return ;
}

Bureaucrat::Bureaucrat(Bureaucrat const & copy) : _name(copy.getName()) {
	*this = copy;
	return ;
}

Bureaucrat::~Bureaucrat(void) {
	return ;
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & b) {
	this->_grade = b._grade;
	return *this;
}

std::string const Bureaucrat::getName(void) const {
	return this->_name;
}

int Bureaucrat::getGrade(void) const {
	return this->_grade;
}

void Bureaucrat::incrementGrade(void) {
	if (this->_grade - 1 < 1) {
		throw Bureaucrat::GradeTooHighException();
		return ;
	}
	this->_grade -=1;
}

void Bureaucrat::decrementGrade(void) {
	if (this->_grade + 1 > 150) {
		throw Bureaucrat::GradeTooLowException();
		return;
	}
	this->_grade +=1;
}

std::ostream & operator<<(std::ostream & o, Bureaucrat const & rhs) {
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << "." << std::endl;
	return o;
}

const char * Bureaucrat::GradeTooHighException::what(void) const throw() {
	return ("Grade too high.");
}

const char * Bureaucrat::GradeTooLowException::what(void) const throw() {
	return ("Grade too low.");
}