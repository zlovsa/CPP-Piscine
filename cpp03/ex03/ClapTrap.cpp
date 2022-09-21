#include <iostream>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _hit_points(100),
						   _max_hit_points(100),
						   _energy_points(100),
						   _max_energy_points(100),
						   _level(1),
						   _name("Player"),
						   _melee_attack_damage(30),
						   _ranged_attack_damage(20),
						   _armor_damage_reduction(5),
						   _type("NoType")
{
	std::cout << "ClapTrap Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(unsigned int hit_points,
				   unsigned int max_hit_points,
				   unsigned int energy_points,
				   unsigned int max_energy_points,
				   unsigned int level,
				   std::string const &name,
				   unsigned int melee_attack_damage,
				   unsigned int ranged_attack_damage,
				   unsigned int armor_damage_reduction,
				   std::string const &type) : _hit_points(hit_points),
									   _max_hit_points(max_hit_points),
									   _energy_points(energy_points),
									   _max_energy_points(max_energy_points),
									   _level(level),
									   _name(name),
									   _melee_attack_damage(melee_attack_damage),
									   _ranged_attack_damage(ranged_attack_damage),
									   _armor_damage_reduction(armor_damage_reduction),
									   _type(type)
{
	std::cout << "ClapTrap Parameter constructor called by " << this->_name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	std::cout << "ClapTrap Copy constructor called on " << other._name << std::endl;
	*this = other;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &other)
{
	std::cout << "ClapTrap Assignation operator called on " << other._name << std::endl;
	this->_hit_points = other._hit_points;
	this->_max_hit_points = other._max_hit_points;
	this->_energy_points = other._energy_points;
	this->_max_energy_points = other._max_energy_points;
	this->_level = other._level;
	this->_name = other._name;
	this->_melee_attack_damage = other._melee_attack_damage;
	this->_ranged_attack_damage = other._ranged_attack_damage;
	this->_armor_damage_reduction = other._armor_damage_reduction;
	this->_type = other._type;
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Destructor called by " << this->_name << std::endl;
}

void ClapTrap::rangedAttack(std::string const &target)
{
	this->print() << " attacks " << target
		<< " at range, causing " << this->_ranged_attack_damage
		<< " points of damage!" << std::endl;
}

void ClapTrap::meleeAttack(std::string const &target)
{
	this->print() << " attacks " << target
		<< " at melee, causing " << this->_melee_attack_damage
		<< " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	this->print() << ".takeDamage(" << amount << ");" << std::endl;
	if (amount > this->_armor_damage_reduction)
	{
		amount -= this->_armor_damage_reduction;
		if (this->_hit_points > amount)
			this->_hit_points -= amount;
		else
			this->_hit_points = 0;
	}
	this->print() << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	this->print() << ".beRepaired(" << amount << ");" << std::endl;
	if (this->_hit_points + amount > this->_max_hit_points)
		this->_hit_points = this->_max_hit_points;
	else
		this->_hit_points += amount;
	this->print() << std::endl;
}

std::ostream &ClapTrap::print() const
{
	return std::cout << this->_type << "." << this->_name
					 << "<HP=" << this->_hit_points
					 << ", EP=" << this->_energy_points
					 << ", ARMOR=" << this->_armor_damage_reduction << ">";
}
