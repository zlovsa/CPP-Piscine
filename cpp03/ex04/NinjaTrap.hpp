#ifndef NINJATRAP_HPP
# define NINJATRAP_HPP
# include <string>
# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class NinjaTrap : virtual public ClapTrap
{
public:
	NinjaTrap();
	NinjaTrap(std::string const &name);
	NinjaTrap(NinjaTrap const &other);
	NinjaTrap &operator=(NinjaTrap const &other);
	~NinjaTrap();

	void ninjaShoebox(ClapTrap &target);
	void ninjaShoebox(FragTrap &target);
	void ninjaShoebox(ScavTrap &target);
	void ninjaShoebox(NinjaTrap &target);
};

#endif