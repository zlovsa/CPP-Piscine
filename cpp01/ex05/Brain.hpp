#ifndef BRAIN_H
# define BRAIN_H
# include <string>

class Brain
{
public:
	Brain(int iq);
	~Brain();
	std::string identify() const;

private:
	int _iq;
};

#endif