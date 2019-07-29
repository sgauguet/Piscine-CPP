#include "ScalarConversion.hpp"

ScalarConversion::ScalarConversion(void) : _type("unknown") {
	return ;
}

ScalarConversion::ScalarConversion(ScalarConversion const & copy) {
	*this = copy;
	return ;
}

ScalarConversion::~ScalarConversion(void) {
	return ;
}

ScalarConversion & ScalarConversion::operator=(ScalarConversion const & b) {
	this->_type = b._type;
	this->_c = b._c;
	this->_i = b._i;
	this->_f = b._f;
	this->_d = b._d;
	this->_infn = b._infn;
	this->_inf = b._inf;
	this->_nan = b._nan;
	return *this;
}

bool		ScalarConversion::isChar(const std::string argv) {
	std::istringstream iss(argv);

	if (argv.length() != 1)
		return false;
	iss >> this->_c;
	if (iss.fail() || isdigit(this->_c) || !std::isprint(this->_c))
		return false;
	return true;
}

bool		ScalarConversion::isInt(const std::string argv) {
	std::istringstream iss(argv);

	if (argv.find('.') != std::string::npos || argv.find('f') != std::string::npos)
		return false;
	iss >> this->_i;
	if (iss.fail())
		return false;
	return true;
}

bool		ScalarConversion::isFloat(const std::string argv) {
	std::istringstream iss(argv);

	if (!argv.compare("-inff") || !argv.compare("+inff") || !argv.compare("nanf"))
		return true;
	if (argv.find('.') == std::string::npos || argv.find('f') == std::string::npos)
		return false;
	iss >> this->_f;
	if (iss.fail())
		return false;
	return true;
}

bool		ScalarConversion::isDouble(const std::string argv) {
	std::istringstream iss(argv);

	if (!argv.compare("-inf") || !argv.compare("+inf") || !argv.compare("nan"))
		return true;
	if (argv.find('.') == std::string::npos || argv.find('f') != std::string::npos)
		return false;
	iss >> this->_d;
	if (iss.fail())
		return false;
	return true;
}

bool		ScalarConversion::isInf(const std::string argv) {

	if (!argv.compare("+inf") || !argv.compare("+inff"))
		this->_inf = true;
	else
		this->_inf = false;
	return this->_inf;
}

bool		ScalarConversion::isInfNeg(const std::string argv) {

	if (!argv.compare("-inf") || !argv.compare("-inff"))
		this->_infn = true;
	else
		this->_infn = false;
	return this->_infn;
}

bool		ScalarConversion::isNan(const std::string argv) {

	if (!argv.compare("nan") || !argv.compare("nanf"))
		this->_nan = true;
	else
		this->_nan = false;
	return this->_nan;
}


std::string ScalarConversion::detectType(const char *argv) {
	isNan(argv);
	isInf(argv);
	isInfNeg(argv);
	if (isChar(argv))
		this->_type = "char";
	else if (isInt(argv))
		this->_type = "int";
	else if (isFloat(argv))
		this->_type = "float";
	else if (isDouble(argv))
		this->_type = "double";
	else
		this->_type = "unknown";
	return this->_type;
}

void ScalarConversion::print_pseudo_literals(const std::string & argv) {
	std::string str(argv);

	if (!str.compare("+inff") || !str.compare("-inff")) {
		str = str.substr(0, str.size() - 1);
	}
	if (!str.compare("nanf")) {
		str = str.substr(0, str.size() - 1);
	}
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << std::fixed << str << "f" << std::endl;
	std::cout << "double: " << std::fixed << str << std::endl;
}

void ScalarConversion::print_literals(int overflow[3]) {
	if (overflow[0]) {
		if (std::isprint(this->_c))
			std::cout << "char: " << this->_c << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	else
		std::cout << "char: " << "impossible" << std::endl;
	if (overflow[1])
		std::cout << "int: " << this->_i << std::endl;
	else
		std::cout << "int: " << "impossible" << std::endl;
	std::cout.precision(1);
	if (overflow[2])
		std::cout << "float: " << std::fixed << this->_f << "f" << std::endl;
	else
		std::cout << "float: " << "impossible" << std::endl;
	std::cout << "double: " << std::fixed << this->_d << std::endl;
}

void ScalarConversion::convertChar(const std::string & argv) {
	int overflow[3];
	overflow[0] = 1;
	overflow[1] = 1;
	overflow[2] = 1;
	this->_i = static_cast<int>(this->_c);
	this->_f = static_cast<float>(this->_c);
	this->_d = static_cast<double>(this->_c);
	if (this->_nan || this->_inf || this->_infn)
		print_pseudo_literals(argv);
	else
		print_literals(overflow);
}

void ScalarConversion::convertInt(const std::string & argv) {
	int overflow[3];
	overflow[0] = (this->_i <= CHAR_MAX && this->_i >= CHAR_MIN);
	overflow[1] = 1;
	overflow[2] = (this->_i <= FLT_MAX && this->_i >= -FLT_MAX);
	this->_c = static_cast<char>(this->_i);
	this->_f = static_cast<float>(this->_i);
	this->_d = static_cast<double>(this->_i);
	if (this->_nan || this->_inf || this->_infn)
		print_pseudo_literals(argv);
	else
		print_literals(overflow);
}

void ScalarConversion::convertFloat(const std::string & argv) {
	int overflow[3];
	overflow[0] = (this->_f <= CHAR_MAX && this->_f>= CHAR_MIN);
	overflow[1] = (this->_f <= INT_MAX && this->_f >= INT_MIN);
	overflow[2] = 1;
	this->_c = static_cast<char>(this->_f);
	this->_i = static_cast<int>(this->_f);
	this->_d = static_cast<double>(this->_f);
	if (this->_nan || this->_inf || this->_infn)
		print_pseudo_literals(argv);
	else
		print_literals(overflow);
}

void ScalarConversion::convertDouble(const std::string & argv) {
	int overflow[3];
	overflow[0] = (this->_d <= CHAR_MAX && this->_d >= CHAR_MIN);
	overflow[1] = (this->_d <= INT_MAX && this->_d >= INT_MIN);
	overflow[2] = (this->_d <= FLT_MAX && this->_d >= -FLT_MAX);
	this->_c = static_cast<char>(this->_d);
	this->_i = static_cast<int>(this->_d);
	this->_f = static_cast<float>(this->_d);
	if (this->_nan || this->_inf || this->_infn)
		print_pseudo_literals(argv);
	else
		print_literals(overflow);
}

void ScalarConversion::printValue(const char *argv) {
	void (ScalarConversion::*f[4])(const std::string & argv);
	std::string types[4] = { "char", "int", "float", "double"};
	int i;

	f[0] = &ScalarConversion::convertChar;
	f[1] = &ScalarConversion::convertInt;
	f[2] = &ScalarConversion::convertFloat;
	f[3] = &ScalarConversion::convertDouble;
	i = 0;
	while (i < 4) {
		if (types[i] == this->_type) {
			(this->*f[i])(argv);
			break ;
		}
		i++;
	}
}
