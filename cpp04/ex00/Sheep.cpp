#include <iostream>
#include <sstream>
#include "Sheep.hpp"

Sheep::Sheep(std::string const &name) : Victim(name)
{
	std::cout << "MEEEEEEEE." << std::endl;
}

Sheep::Sheep(const Sheep &other) : Victim(other)
{
}

Sheep &Sheep::operator=(Sheep const &other)
{
	Victim::operator=(other);
	return *this;
}

Sheep::~Sheep()
{
	std::cout << "Bleat..." << std::endl;
}

void Sheep::getPolymorphed() const
{
	std::cout << this->getName() << " has been turned into a turtle!"
		<< std::endl;
}
