#ifndef SQUAD_H
#define SQUAD_H

#include "ISquad.hpp"
#include <iostream>

class Squad : public ISquad {

typedef struct		s_units
{
	ISpaceMarine*	nth;
	ISpaceMarine*	addr;
	struct s_units	*next;
}					t_units;

public:

	Squad(void);
	Squad(std::string const & name, int apcost, int damage);
	Squad(Squad const & copy);
	virtual ~Squad(void);
	Squad & operator=(Squad const & b);

	int getCount(void) const;
	ISpaceMarine* getUnit(int nth) const;
	int push(ISpaceMarine* unit);

private:

	int _units;
	t_units * _first;
};

#endif
