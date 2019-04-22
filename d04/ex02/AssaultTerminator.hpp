#ifndef ASSAULTTERMINATOR_H
#define ASSAULTTERMINATOR_H

#include <iostream>
#include "ISpaceMarine.hpp"

class AssaultTerminator : public ISpaceMarine
{

public:
	AssaultTerminator(void);
	AssaultTerminator(AssaultTerminator const & copy);
	virtual ~AssaultTerminator(void);
	AssaultTerminator & operator=(AssaultTerminator const & );

	ISpaceMarine * clone() const;
	void battleCry() const;
	void rangedAttack() const;
	void meleeAttack() const;
};

#endif
