#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP
#include <string>

class ScavTrap
{
public:
	ScavTrap();
	ScavTrap(std::string const &name);
	ScavTrap(ScavTrap const &other);
	ScavTrap &operator=(ScavTrap const &other);
	~ScavTrap();
	void rangedAttack(std::string const &target);
	void meleeAttack(std::string const &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void challengeNewcomer(std::string const &target);

protected:
	unsigned int _hit_points;
	unsigned int _max_hit_points;
	unsigned int _energy_points;
	unsigned int _max_energy_points;
	unsigned int _level;
	std::string _name;
	unsigned int _melee_attack_damage;
	unsigned int _ranged_attack_damage;
	unsigned int _armor_damage_reduction;
	std::ostream &print(std::string const &before) const;
};

#endif