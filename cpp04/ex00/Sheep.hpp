#ifndef SHEEP_HPP
#define SHEEP_HPP
#include <string>
#include "Victim.hpp"

class Sheep : public Victim
{
public:
	Sheep(std::string const &name);
	Sheep(Sheep const &other);
	Sheep &operator=(Sheep const &other);
	virtual ~Sheep();
	void getPolymorphed() const;

private:
	Sheep();
};

#endif