#include "OfficeBlock.hpp"

OfficeBlock::OfficeBlock(void) :  _intern(NULL), _signingBureaucrat(NULL), _executingBureaucrat(NULL) {
	return ;
}

OfficeBlock::OfficeBlock(Intern & intern, Bureaucrat & sign, Bureaucrat & exec) : _intern(intern), _signingBureaucrat(sign), _executingBureaucrat(exec) {
	return ;
}

OfficeBlock::~OfficeBlock(void) {
	return ;
}

void  OfficeBlock::setIntern(Intern & intern) {
	if (intern != NULL)
		this->_intern = &intern;
}

void  OfficeBlock::setSigner(Bureaucrat & sign) {
	if (sign != NULL)
		this->_signingBureaucrat = &sign;
}

void  OfficeBlock::setExecutor(Bureaucrat & exec) {
	if (exec != NULL)
		this->_executingBureaucrat = &exec;
}

void  OfficeBlock::doBureaucracy(std::string formName, std::string target) {
	Form & form;
	if (this->_intern == NULL)
		throw OfficeBlock::paramException("intern");
	form = this->_intern->makeForm(formName, formTarget);
	if (form == NULL)
		throw OfficeBlock::formException(formName);
	if (this->_signingBureaucrat == NULL)
		throw OfficeBlock::paramException("signer");
	this->_signingBureaucrat->signForm(form);
	if (this->_executingBureaucrat == NULL)
		throw OfficeBlock::paramException("executor");
	this->_executingBureaucrat->executeForm(form);
}


/* formException */

OfficeBlock::formException::formException(void) {
	return ;
}

OfficeBlock::formException::formException(std::string formName) : _formName(formname) {
	return ;
}

OfficeBlock::formException::formException(formException const & copy) {
	*this = copy;
	return ;
}

OfficeBlock::formException::~formException(void) throw() {
	return ;
}

OfficeBlock::formException & OfficeBlock::formException::operator=(formException const &) {
	this->_formName = b._formName;
	return *this;
}

const char * OfficeBlock::formException::what(void) const throw() {
	return ("Intern cannot create form.");
}

/* paramException */

OfficeBlock::paramException::paramException(void) {
	return ;
}

OfficeBlock::paramException::paramException(std::string param) : _param(param) {
	return ;
}

OfficeBlock::paramException::paramException(paramException const & copy) {
	*this = copy;
	return ;
}

OfficeBlock::paramException::~paramException(void) throw() {
	return ;
}

OfficeBlock::paramException & OfficeBlock::paramException::operator=(paramException const &) {
	this->_param = b._param;
	return *this;
}

const char * OfficeBlock::paramException::what(void) const throw() {
	return ("Intern cannot create form.");
}

