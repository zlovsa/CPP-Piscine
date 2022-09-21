#ifndef ZOMBIEEVENT_H
#define ZOMBIEEVENT_H
#include <string>
#include "Zombie.hpp"

class ZombieEvent
{

public:
				ZombieEvent();
				~ZombieEvent();
	void		setZombieType(std::string type);
	Zombie		*newZombie(std::string name) const;
	void		randomChump() const;

private:
	std::string _type;
};

#endif