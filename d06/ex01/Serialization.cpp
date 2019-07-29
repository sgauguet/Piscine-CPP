#include "Serialization.hpp"

Serialization::Serialization(void) {
	return ;
}

Serialization::Serialization(Serialization const & copy) {
	*this = copy;
	return ;
}

Serialization::~Serialization(void) {
	return ;
}

Serialization & Serialization::operator=(Serialization const & b) {
	int i;

	i = 0;
	while (i < 9) {
		this->_a1[i] = b._a1[i];
		this->_a2[i] = b._a2[i];
		i++;
	}
	this->_i = b._i;
	return *this;
}
	
void 	Serialization::randomArray(void) {
	int i;
	int random_number, max_value = 126, min_value = 33;

	i = 0;
	while (i < 8) {
		random_number = rand() % (max_value - min_value) + min_value;
		this->_a1[i] = static_cast<char>(random_number);
		i++;
	}
	this->_a1[i] = '\0';
	i = 0;
	while (i < 8) {
		random_number = rand() % (max_value - min_value) + min_value;
		this->_a2[i] = static_cast<char>(random_number);
		i++;
	}
	this->_a2[i] = '\0';
}

void	Serialization::randomInt(void) {
	int random_number, max_value = static_cast<int>(INT_MAX), min_value = 1;
	random_number = rand() % (max_value - min_value) + min_value;
	if (rand() % 2)
		random_number *= -1;
	this->_i = random_number;
}

void	Serialization::printAttributes(void) {
	std::cout << "----- Random bytes to serialize -----" << std::endl;
	std::cout << "array1 : " << this->_a1 << std::endl;
	std::cout << "int i  : " << this->_i << std::endl;
	std::cout << "array2 : " << this->_a2 << std::endl;
	std::cout << std::endl;
}

void	*Serialization::serialize(void) {
	char *raw;
	unsigned int i;

	randomArray();
	randomInt();
	printAttributes();

	raw = new char[20];
	i = 0;
	while (i < 8) {
		raw[i] = this->_a1[i];
		i++;
	}
	raw[8] = static_cast<char>(this->_i & 0xff);
	raw[9] = static_cast<char>((this->_i >> 8) & 0xff);
	raw[10] = static_cast<char>((this->_i >> 16) & 0xff);
	raw[11] = static_cast<char>((this->_i >> 24) & 0xff);
	i = 12;
	while (i < 20) {
		raw[i] = this->_a2[i - 12];
		i++;
	}
	std::cout << "----- serialization result -----" << std::endl;
	std::cout << raw << std::endl;
	std::cout << std::endl;

	return static_cast<void *>(raw);
}

Data	*Serialization::deserialize(void * raw) {
	Data *result;
	std::string str(reinterpret_cast<char *>(raw));

	result = new Data;
	result->s1 = str.substr(0,8);
	result->n = (static_cast<unsigned char>(str[11]) << 24)
		| (static_cast<unsigned char>(str[10]) << 16)
		| (static_cast<unsigned char>(str[9]) << 8)
		| static_cast<unsigned char>(str[8]);
	result->s2 = str.substr(str.length() - 8, str.length());
	return result;
}
