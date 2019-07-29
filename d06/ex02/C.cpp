#include "C.hpp"
#include <iostream> 

C::C(void) {
	std::cout << "C created" << std::endl;
	return ;
}

C::C(C const & copy) {
	*this = copy;
	return ;
}

C::~C(void) {
	return ;
}

C & C::operator=(C const &) {
	return *this;
}
