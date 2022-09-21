#ifndef RADSCORPION_HPP
# define RADSCORPION_HPP
# include <string>
# include "Enemy.hpp"

class RadScorpion : public Enemy
{
public:
	RadScorpion();
	virtual ~RadScorpion();

private:
	RadScorpion(RadScorpion const &other);
	RadScorpion &operator=(RadScorpion const &other);
};

#endif