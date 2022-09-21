#ifndef AXE_HPP
# define AXE_HPP
# include <string>
# include "AWeapon.hpp"

class Axe : public AWeapon
{
public:
	Axe();
	virtual ~Axe();
	void attack() const;

private:
	Axe(Axe const &other);
	Axe &operator=(Axe const &other);
};

#endif