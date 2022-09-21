#include "ZombieEvent.hpp"
#include <iostream>
#include <string>

ZombieEvent::ZombieEvent()
{
	return;
}

ZombieEvent::~ZombieEvent()
{
	return;
}

void ZombieEvent::setZombieType(std::string type)
{
	this->_type = type;
	return;
}

Zombie* ZombieEvent::newZombie(std::string name) const
{
	return new Zombie(name, this->_type);
}

void ZombieEvent::randomChump() const
{
	static std::string names[8] = {"Alice", "Bob", "Mike", "Tom",
		"Jack", "John", "Cobb", "Dwayne" };

	Zombie *zombie = newZombie(names[std::rand() % 8]);
	zombie->announce();
	delete zombie;
	return;
}