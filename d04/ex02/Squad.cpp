#include "Squad.hpp"

Squad::Squad(void) : _units(0), _first(NULL) {
	return ;
}

Squad::Squad(Squad const & copy) : _units(0), _first(NULL) {
	for (int i = 0; i < copy.getCount(); i++) {
		this->push(copy.getUnit(i));
	}
	std::cout << "Squad is copied." << std::endl;
	return ;
}

Squad::~Squad( void ) {
	t_units *tmp;
	t_units *current;

	current = this->_first;
	while (current) {
		tmp = current;
		current = current->next;
		delete tmp->nth;
		delete tmp;
	}
	return ;
}

Squad & Squad::operator=(Squad const & b) {
	t_units *tmp;
	t_units *current;

	current = this->_first;
	while (current) {
		tmp = current;
		current = current->next;
		delete tmp->nth;
		delete tmp;
	}
	this->_units = 0;
	this->_first = NULL;
	for (int i = 0; i < b.getCount(); i++) {
		this->push(b.getUnit(i));
	}
	std::cout << "Assignment operator called." << std::endl;
	return *this;
}

int Squad::getCount(void) const {
	return this->_units;
}

ISpaceMarine* Squad::getUnit(int nth) const {
	t_units *result;
	if (this->getCount() < nth)
		return NULL;
	result = this->_first;
	while (nth--) {
		result = result->next;
	}
	return result->nth;
}

int Squad::push(ISpaceMarine* unit) {
	if (unit == NULL)
		return this->_units;
	t_units *elem = new t_units;
	t_units *tmp;

	elem->nth = unit->clone();
	elem->addr = unit;
	elem->next = NULL;
	tmp = this->_first;
	if (this->getCount() == 0)
		this->_first = elem;
	else {
		if (tmp->addr == unit) {
			delete elem->nth;
			delete elem;
			return this->_units;
		}
		while (tmp && tmp->next) {
			if (tmp->addr == unit) {
				delete elem->nth;
				delete elem;
				return this->_units;
			}
			tmp = tmp->next;
		}
		tmp->next = elem;
	}
	this->_units += 1;
	return this->_units;
}
