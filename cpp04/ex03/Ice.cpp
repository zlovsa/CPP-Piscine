#include <iostream>
#include "ICharacter.hpp"
#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
}

Ice::Ice(const Ice &other) : AMateria(other)
{
}

Ice &Ice::operator=(Ice const &other)
{
	AMateria::operator=(other);
	return *this;
}

Ice::~Ice()
{
}

Ice *Ice::clone() const
{
	return new Ice(*this);
}

void Ice::use(ICharacter &target)
{
	AMateria::use(target);
	std::cout << "* shoots an ice bolt at "
			  << target.getName() << " *" << std::endl;
}
