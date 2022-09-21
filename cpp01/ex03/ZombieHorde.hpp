#ifndef ZOMBIEHORDE_H
#define ZOMBIEHORDE_H
#include <string>
#include "Zombie.hpp"

class ZombieHorde
{

public:
	ZombieHorde(int N);
	~ZombieHorde();
	void announce(void) const;

private:
	int _N;
	Zombie* _zombies;
};

#endif