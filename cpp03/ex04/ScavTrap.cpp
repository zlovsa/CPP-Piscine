#include <iostream>
#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) :
	ClapTrap(100, 100, 50, 50, 1, "Player", 20, 15, 3, "SC4V-TP")
{
	std::cout << "SC4V-TP Default constructor called by " << this->_name << std::endl;
}

ScavTrap::ScavTrap(std::string const &name) :
	ClapTrap(100, 100, 50, 50, 1, name, 20, 15, 3, "SC4V-TP")
{
	std::cout << "SC4V-TP Parameter constructor called by " << this->_name << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &other)
{
	std::cout << "SC4V-TP Copy constructor called on " << other._name << std::endl;
	*this = other;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &other)
{
	std::cout << "SC4V-TP Assignation operator called on " << other._name << std::endl;
	ClapTrap::operator=(other);
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "SC4V-TP Destructor called by " << this->_name << std::endl;
}

void ScavTrap::challengeNewcomer(std::string const &target)
{
	std::string challenges[5] = {"Kill Strelok",
								"Find the documents in X18",
								"Disable the Brain Scorcher",
								"Find out what happened to Ghost"};
	int choice = std::rand() % 4;
	this->print() << " get new challenge for " << target
		<< ": " << challenges[choice] << std::endl;
}
