#ifndef PEON_HPP
#define PEON_HPP
#include <string>
#include "Victim.hpp"

class Peon : public Victim
{
public:
	Peon(std::string const &name);
	Peon(Peon const &other);
	Peon &operator=(Peon const &other);
	virtual ~Peon();
	void getPolymorphed() const;

private:
	Peon();
};

#endif