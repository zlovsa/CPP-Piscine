#ifndef ICE_HPP
# define ICE_HPP
# include <string>
# include "AMateria.hpp"

class Ice : public AMateria
{
public:
	Ice();
	Ice(Ice const &other);
	Ice &operator=(Ice const &other);
	virtual ~Ice();

	virtual Ice *clone() const;
	virtual void use(ICharacter &target);
};

#endif