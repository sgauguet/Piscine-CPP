#include "Base.hpp"

Base::Base(void) {
	return ;
}

Base::Base(Base const & copy) {
	*this = copy;
	return ;
}

Base::~Base(void) {
	return ;
}

Base & Base::operator=(Base const &) {
	return *this;
}
