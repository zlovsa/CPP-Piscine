#include <iostream>
#include <sstream>
#include "Peon.hpp"

Peon::Peon(std::string const &name) : Victim(name)
{
	std::cout << "Zog zog." << std::endl;
}

Peon::Peon(const Peon &other) : Victim(other)
{
}

Peon &Peon::operator=(Peon const &other)
{
	Victim::operator=(other);
	return *this;
}

Peon::~Peon()
{
	std::cout << "Bleuark..." << std::endl;
}

void Peon::getPolymorphed() const
{
	std::cout << this->getName() << " has been turned into a pink pony!"
			  << std::endl;
}
