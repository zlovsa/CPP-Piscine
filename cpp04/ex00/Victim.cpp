#include <iostream>
#include <sstream>
#include "Victim.hpp"

Victim::Victim()
{
}

Victim::Victim(std::string const &name) : _name(name)
{
	std::cout << "Some random victim called " << this->_name
		<< " just appeared!" << std::endl;
}

Victim::Victim(const Victim &other)
{
	*this = other;
}

Victim &Victim::operator=(Victim const &other)
{
	this->_name = other._name;
	return *this;
}

Victim::~Victim()
{
	std::cout << "Victim " << this->_name
		<< " just died for no apparent reason!" << std::endl;
}

std::string const &Victim::getName() const
{
	return this->_name;
}

void Victim::getPolymorphed() const
{
	std::cout << this->_name
		<< " has been turned into a cute little sheep!" << std::endl;
}

std::ostream &operator<<(std::ostream &o, Victim const &v)
{
	o << "I am " << v.getName() << " and I like otters!" << std::endl;
	return o;
}
