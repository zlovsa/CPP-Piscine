#ifndef OGRE_HPP
# define OGRE_HPP
# include <string>
# include "Enemy.hpp"

class Ogre : public Enemy
{
public:
	Ogre();
	virtual ~Ogre();
	void takeDamage(int damage);

private:
	Ogre(Ogre const &other);
	Ogre &operator=(Ogre const &other);
};

#endif