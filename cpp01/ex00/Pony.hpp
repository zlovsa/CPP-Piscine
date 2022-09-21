#ifndef PONY_H
# define PONY_H
# include <string>

class Pony{

public:
	Pony(std::string name);
	~Pony();
	void greet(void) const;

private:
	std::string _name;
};

#endif