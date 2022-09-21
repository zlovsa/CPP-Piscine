#ifndef HUMAN_H
# define HUMAN_H
# include <string>
# include "Brain.hpp"

class Human
{
public:
	Human();
	~Human();
	const Brain& getBrain() const;
	std::string identify() const;

private:
	Brain _brain;
};

#endif