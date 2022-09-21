#include <iostream>
#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap(100, 100, 100, 100, 1, "Player", 30, 20, 5, "FR4G-TP")
{
	std::cout << "FR4G-TP Default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string const &name) : ClapTrap(100, 100, 100, 100, 1, name, 30, 20, 5, "FR4G-TP")
{
	std::cout << "FR4G-TP Parameter constructor called by " << this->_name << std::endl;
}

FragTrap::FragTrap(const FragTrap &other)
{
	std::cout << "FR4G-TP Copy constructor called on " << other._name << std::endl;
	*this = other;
}

FragTrap &FragTrap::operator=(FragTrap const &other)
{
	std::cout << "FR4G-TP Assignation operator called on " << other._name << std::endl;
	ClapTrap::operator=(other);
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FR4G-TP Destructor called by " << this->_name << std::endl;
}

void FragTrap::vaulthunter_dot_exe(std::string const &target)
{
	this->print() << ".vaulthunder_dot_exe(" << target << ");" << std::endl;
	if (this->_energy_points < 25)
		std::cout << "Not enough energy points!!!" << std::endl;
	else
	{
		this->_energy_points -= 25;
		std::string attacks[5] = {"axe", "shotgun",
								  "nailgun", "rocket", "thunderbolt"};
		unsigned int amounts[5] = {20, 30, 8, 35, 6};
		int choice = std::rand() % 5;
		this->print() << " attacks " << target
			<< " with " << attacks[choice] << ", causing " << amounts[choice]
			<< " points of damage!" << std::endl;
	}
	this->print() << std::endl;
}
