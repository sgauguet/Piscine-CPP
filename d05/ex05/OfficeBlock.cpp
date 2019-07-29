#include "OfficeBlock.hpp"

OfficeBlock::OfficeBlock(void) :  _intern(NULL), _signingBureaucrat(NULL), _executingBureaucrat(NULL) {
	return ;
}

OfficeBlock::OfficeBlock(Intern & intern, Bureaucrat & sign, Bureaucrat & exec) : _intern(&intern), _signingBureaucrat(&sign), _executingBureaucrat(&exec) {
	return ;
}

OfficeBlock::~OfficeBlock(void) {
	if (this->_intern != NULL)
		delete this->_intern;
	if (this->_signingBureaucrat != NULL)
		delete this->_signingBureaucrat ;
	if (this->_executingBureaucrat != NULL)
		delete this->_executingBureaucrat;
	return ;
}

int  OfficeBlock::getIntern(void) {
	int ret = (this->_intern == NULL) ? 0 : 1;
	return ret;
}

int  OfficeBlock::getSigner(void) {
	int ret = (this->_signingBureaucrat == NULL) ? 0 : 1;
	return ret;
}

int  OfficeBlock::getExecutor(void) {
	int ret = (this->_executingBureaucrat == NULL) ? 0 : 1;
	return ret;
}

void OfficeBlock::setIntern(Intern & intern) {
	if (&intern != NULL)
		this->_intern = &intern;
}

void OfficeBlock::setSigner(Bureaucrat & sign) {
	if (&sign != NULL)
		this->_signingBureaucrat = &sign;
}

void OfficeBlock::setExecutor(Bureaucrat & exec) {
	if (&exec != NULL)
		this->_executingBureaucrat = &exec;
}

void  OfficeBlock::doBureaucracy(std::string formName, std::string target) {
	Form * form;
	if (this->_intern == NULL)
		throw OfficeBlock::paramException("Intern");
	if (this->_signingBureaucrat == NULL)
		throw OfficeBlock::paramException("Signer");
	if (this->_executingBureaucrat == NULL)
		throw OfficeBlock::paramException("Executor");

	form = this->_intern->makeForm(formName, target);
	if (form == NULL)
		throw OfficeBlock::formException(formName);
	this->_signingBureaucrat->signForm(*form);
	this->_executingBureaucrat->executeForm(*form);
}

OfficeBlock::OfficeBlock(OfficeBlock const & copy) {
	*this = copy;
	return ;
}


OfficeBlock & OfficeBlock::operator=(OfficeBlock const & b) {
	this->_intern = b._intern;
	this->_signingBureaucrat = b._signingBureaucrat;
	this->_executingBureaucrat = b._executingBureaucrat;
	return *this;
}

/* formException */

OfficeBlock::formException::formException(void) {
	return ;
}

OfficeBlock::formException::formException(std::string formName) : _formName(formName) {
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
	return *this;
}

const char * OfficeBlock::formException::what(void) const throw() {
	std::stringstream ss;
	std::string str;
	
	ss << "Intern cannot create form " << this->_formName << ". This name is unknown.";
	str = ss.str();
	const char *result = str.c_str();
	return result;
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
	return *this;
}

const char * OfficeBlock::paramException::what(void) const throw() {
	std::stringstream ss;
	std::string str;
	
	ss << "OfficeBlock can't do bureaucracy. " << this->_param << " missing.";
	str = ss.str();
	const char *result = str.c_str();
	return result;
}

