#include <iostream>
#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap(void) :
	ClapTrap(60, 60, 120, 120, 1, "Player", 60, 5, 0, "INAC")
{
	std::cout << "INAC Default constructor called by " << this->_name << std::endl;
}

NinjaTrap::NinjaTrap(std::string const &name) :
	ClapTrap(60, 60, 120, 120, 1, name, 60, 5, 0, "INAC")
{
	std::cout << "INAC Parameter constructor called by " << this->_name << std::endl;
}

NinjaTrap::NinjaTrap(const NinjaTrap &other)
{
	std::cout << "INAC Copy constructor called on " << other._name << std::endl;
	*this = other;
}

NinjaTrap &NinjaTrap::operator=(NinjaTrap const &other)
{
	std::cout << "INAC Assignation operator called on " << other._name << std::endl;
	ClapTrap::operator=(other);
	return *this;
}

NinjaTrap::~NinjaTrap()
{
	std::cout << "INAC Destructor called by " << this->_name << std::endl;
}

void NinjaTrap::ninjaShoebox(ClapTrap &target)
{
	this->print() << " special action with ClapTrap:" << std::endl;
	target.takeDamage(31);
}

void NinjaTrap::ninjaShoebox(FragTrap &target)
{
	this->print() << " special action with FragTrap:" << std::endl;
	target.vaulthunter_dot_exe("void");
}

void NinjaTrap::ninjaShoebox(ScavTrap &target)
{
	this->print() << " special action with ScavTrap:" << std::endl;
	target.challengeNewcomer("random");
}

void NinjaTrap::ninjaShoebox(NinjaTrap &target)
{
	this->print() << " special action with NinjaTrap:" << std::endl;
	target.beRepaired(71);
}
