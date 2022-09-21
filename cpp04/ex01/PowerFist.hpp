#ifndef POWERFIST_HPP
# define POWERFIST_HPP
# include <string>
# include "AWeapon.hpp"

class PowerFist : public AWeapon
{
public:
	PowerFist();
	virtual ~PowerFist();
	void attack() const;

private:
	PowerFist(PowerFist const &other);
	PowerFist &operator=(PowerFist const &other);
};

#endif