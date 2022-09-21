#include <string>
#include <sstream>
#include "Brain.hpp"

Brain::Brain(int iq):_iq(iq)
{
	return;
}

Brain::~Brain()
{
	return;
}

std::string Brain::identify() const
{
	std::stringstream ss;
	ss << this;
	std::string id;
	ss >> id;
	return id;
}