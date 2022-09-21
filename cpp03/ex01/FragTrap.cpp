#include <iostream>
#include "FragTrap.hpp"

FragTrap::FragTrap(void) : _hit_points(100),
						   _max_hit_points(100),
						   _energy_points(100),
						   _max_energy_points(100),
						   _level(1),
						   _name("Player"),
						   _melee_attack_damage(30),
						   _ranged_attack_damage(20),
						   _armor_damage_reduction(5)
{
	std::cout << "FR4G-TP Default constructor called by " << this->_name << std::endl;
}

FragTrap::FragTrap(std::string const &name) : _hit_points(100),
											  _max_hit_points(100),
											  _energy_points(100),
											  _max_energy_points(100),
											  _level(1),
											  _name(name),
											  _melee_attack_damage(30),
											  _ranged_attack_damage(20),
											  _armor_damage_reduction(5)
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
	this->_hit_points = other._hit_points;
	this->_max_hit_points = other._max_hit_points;
	this->_energy_points = other._energy_points;
	this->_max_energy_points = other._max_energy_points;
	this->_level = other._level;
	this->_name = other._name;
	this->_melee_attack_damage = other._melee_attack_damage;
	this->_ranged_attack_damage = other._ranged_attack_damage;
	this->_armor_damage_reduction = other._armor_damage_reduction;
	return *this;
}

FragTrap::~FragTrap()
{
	this->print("FR4G-TP Destructor called by ") << std::endl;
}

void FragTrap::rangedAttack(std::string const &target)
{
	this->print("FR4G-TP ") << " attacks " << target
							<< " at range, causing " << this->_ranged_attack_damage
							<< " points of damage!" << std::endl;
}

void FragTrap::meleeAttack(std::string const &target)
{
	this->print("FR4G-TP ") << " attacks " << target
							<< " at melee, causing " << this->_melee_attack_damage
							<< " points of damage!" << std::endl;
}

void FragTrap::takeDamage(unsigned int amount)
{
	this->print("FR4G-TP ") << ".takeDamage(" << amount << ");" << std::endl;
	if (amount > this->_armor_damage_reduction)
	{
		amount -= this->_armor_damage_reduction;
		if (this->_hit_points > amount)
			this->_hit_points -= amount;
		else
			this->_hit_points = 0;
	}
	this->print("FR4G-TP ") << std::endl;
}

void FragTrap::beRepaired(unsigned int amount)
{
	this->print("FR4G-TP ") << ".beRepaired(" << amount << ");" << std::endl;
	if (this->_hit_points + amount > this->_max_hit_points)
		this->_hit_points = this->_max_hit_points;
	else
		this->_hit_points += amount;
	this->print("FR4G-TP ") << std::endl;
}

std::ostream &FragTrap::print(std::string const &before) const
{
	return std::cout << before << this->_name
					 << "<HP=" << this->_hit_points
					 << ", EP=" << this->_energy_points
					 << ", ARMOR=" << this->_armor_damage_reduction << ">";
}

void FragTrap::vaulthunter_dot_exe(std::string const &target)
{
	this->print("FR4G-TP ") << ".vaulthunder_dot_exe(" << target << ");" << std::endl;
	if (this->_energy_points < 25)
		std::cout << "Not enough energy points!!!" << std::endl;
	else
	{
		this->_energy_points -= 25;
		std::string attacks[5] = {"axe", "shotgun",
								  "nailgun", "rocket", "thunderbolt"};
		unsigned int amounts[5] = {20, 30, 8, 35, 6};
		int choice = std::rand() % 5;
		this->print("FR4G-TP ") << " attacks " << target
								<< " with " << attacks[choice] << ", causing " << amounts[choice]
								<< " points of damage!" << std::endl;
	}
	this->print("FR4G-TP ") << std::endl;
}