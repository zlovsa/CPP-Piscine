#ifndef PLASMARIFLE_HPP
# define PLASMARIFLE_HPP
# include <string>
# include "AWeapon.hpp"

class PlasmaRifle : public AWeapon
{
public:
	PlasmaRifle();
	virtual ~PlasmaRifle();
	void attack() const;

private:
	PlasmaRifle(PlasmaRifle const &other);
	PlasmaRifle &operator=(PlasmaRifle const &other);
};

#endif