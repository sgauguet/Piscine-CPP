#ifndef TACTICALMARINE_H
#define TACTICALMARINE_H

#include <iostream>
#include "ISpaceMarine.hpp"

class TacticalMarine : public ISpaceMarine
{

public:
	TacticalMarine(void);
	TacticalMarine(TacticalMarine const & copy);
	virtual ~TacticalMarine(void);
	TacticalMarine & operator=(TacticalMarine const & );

	ISpaceMarine * clone() const;
	void battleCry() const;
	void rangedAttack() const;
	void meleeAttack() const;
};

#endif
