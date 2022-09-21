#include <iostream>
#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : _hit_points(100),
						   _max_hit_points(100),
						   _energy_points(50),
						   _max_energy_points(50),
						   _level(1),
						   _name("Player"),
						   _melee_attack_damage(20),
						   _ranged_attack_damage(15),
						   _armor_damage_reduction(3)
{
	std::cout << "SC4V-TP Default constructor called by " << this->_name << std::endl;
}

ScavTrap::ScavTrap(std::string const &name) : _hit_points(100),
									   _max_hit_points(100),
									   _energy_points(50),
									   _max_energy_points(50),
									   _level(1),
									   _name(name),
									   _melee_attack_damage(20),
									   _ranged_attack_damage(15),
									   _armor_damage_reduction(3)
{
	std::cout << "SC4V-TP Parameter constructor called by " << this->_name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other)
{
	std::cout << "SC4V-TP Copy constructor called on " << other._name << std::endl;
	*this = other;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &other)
{
	std::cout << "SC4V-TP Assignation operator called on " << other._name << std::endl;
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

ScavTrap::~ScavTrap()
{
	this->print("SC4V-TP Destructor called by ") << std::endl;
}

void ScavTrap::rangedAttack(std::string const &target)
{
	this->print("SC4V-TP ") << " attacks " << target
		<< " at range, causing " << this->_ranged_attack_damage
		<< " points of damage!" << std::endl;
}

void ScavTrap::meleeAttack(std::string const &target)
{
	this->print("SC4V-TP ") << " attacks " << target
		<< " at melee, causing " << this->_melee_attack_damage
		<< " points of damage!" << std::endl;
}

void ScavTrap::takeDamage(unsigned int amount)
{
	this->print("SC4V-TP ") << ".takeDamage(" << amount << ");" << std::endl;
	if (amount > this->_armor_damage_reduction)
	{
		amount -= this->_armor_damage_reduction;
		if (this->_hit_points > amount)
			this->_hit_points -= amount;
		else
			this->_hit_points = 0;
	}
	this->print("SC4V-TP ") << std::endl;
}

void ScavTrap::beRepaired(unsigned int amount)
{
	this->print("SC4V-TP ") << ".beRepaired(" << amount << ");" << std::endl;
	if (this->_hit_points + amount > this->_max_hit_points)
		this->_hit_points = this->_max_hit_points;
	else
		this->_hit_points += amount;
	this->print("SC4V-TP ") << std::endl;
}

std::ostream &ScavTrap::print(std::string const &before) const
{
	return std::cout << before << this->_name
					 << "<HP=" << this->_hit_points
					 << ", EP=" << this->_energy_points
					 << ", ARMOR=" << this->_armor_damage_reduction << ">";
}

void ScavTrap::challengeNewcomer(std::string const &target)
{
	std::string challenges[4] = {"Kill Strelok",
								"Find the documents in X18",
								"Disable the Brain Scorcher",
								"Find out what happened to Ghost"};
	int choice = std::rand() % 4;
	this->print("SC4V-TP ") << " get new challenge for " << target
							<< ": " << challenges[choice] << std::endl;
}