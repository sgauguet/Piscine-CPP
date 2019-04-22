#ifndef AWEAPON_H
#define AWEAPON_H

#include <iostream>

class AWeapon {

public:

	AWeapon(void);
	AWeapon(std::string const & name, int apcost, int damage);
	AWeapon(AWeapon const & copy);
	virtual ~AWeapon(void);
	AWeapon & operator=(AWeapon const & b);

	std::string getName(void) const;
	int getAPCost(void) const;
	int getDamage(void) const;
	void setName(std::string name);
	void setAPCost(int apcost);
	void setDamage(int damage);


	virtual void attack(void) const = 0;

private:

	std::string _name;
	int _APCost;
	int _damage;

};

#endif
