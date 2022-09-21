#include "ZombieHorde.hpp"
#include <iostream>
#include <string>

ZombieHorde::ZombieHorde(int N) : _N(N)
{
	std::cout << "Start creating horde of " << _N << " zombies..." << std::endl;
	this->_zombies = new Zombie[this->_N];
	std::cout << "Horde of " << _N << " zombies created." << std::endl;
	return;
}

ZombieHorde::~ZombieHorde()
{
	std::cout << "Start destroying horde of " << _N << " zombies..." << std::endl;
	delete[] this->_zombies;
	std::cout << "Horde of " << _N << " zombies destroyed." << std::endl;
	return;
}

void ZombieHorde::announce(void) const
{
	std::cout << "Horde of " << _N << " zombies greets you!" << std::endl;
	for (int i = 0; i < this->_N; i++)
		this->_zombies[i].announce();
	return;
}
