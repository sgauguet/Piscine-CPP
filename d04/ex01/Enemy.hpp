#ifndef ENEMY_H
#define ENEMY_H

#include <iostream>

class Enemy {

public:

	Enemy(void);
	Enemy(int hp, std::string const & type);
	Enemy(Enemy const & copy);
	virtual ~Enemy(void);
	Enemy & operator=(Enemy const & b);

	std::string getType(void) const;
	void setType(std::string type);
	int getHP(void) const;
	void setHP(int hp);

	virtual void takeDamage(int amount);

private:

	std::string _type;
	int _HP;

};

#endif
