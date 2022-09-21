#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP
#include <string>

class FragTrap
{
public:
	FragTrap();
	FragTrap(std::string const &name);
	FragTrap(FragTrap const &other);
	FragTrap &operator=(FragTrap const &other);
	~FragTrap();
	void rangedAttack(std::string const &target);
	void meleeAttack(std::string const &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void vaulthunter_dot_exe(std::string const &target);

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