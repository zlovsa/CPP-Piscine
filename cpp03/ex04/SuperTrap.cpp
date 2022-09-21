#include <iostream>
#include "SuperTrap.hpp"

SuperTrap::SuperTrap(void) :
	ClapTrap(100, 100, 120, 120, 1, "Player", 60, 20, 5, "STrap")
{
	std::cout << "STrap Default constructor called by " << this->_name << std::endl;
}

SuperTrap::SuperTrap(std::string const &name) :
	ClapTrap(100, 100, 120, 120, 1, name, 60, 20, 5, "STrap")
{
	std::cout << "STrap Parameter constructor called by " << this->_name << std::endl;
}

SuperTrap::SuperTrap(const SuperTrap &other)
{
	std::cout << "STrap Copy constructor called on " << other._name << std::endl;
	*this = other;
}

SuperTrap &SuperTrap::operator=(SuperTrap const &other)
{
	std::cout << "STrap Assignation operator called on " << other._name << std::endl;
	ClapTrap::operator=(other);
	return *this;
}

SuperTrap::~SuperTrap()
{
	std::cout << "STrap Destructor called by " << this->_name << std::endl;
}
