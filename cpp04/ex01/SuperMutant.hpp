#ifndef SUPERMUTANT_HPP
# define SUPERMUTANT_HPP
# include <string>
# include "Enemy.hpp"

class SuperMutant : public Enemy
{
public:
	SuperMutant();
	virtual ~SuperMutant();
	void takeDamage(int damage);

private:
	SuperMutant(SuperMutant const &other);
	SuperMutant &operator=(SuperMutant const &other);
};

#endif