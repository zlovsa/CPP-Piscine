#ifndef ZOMBIE_H
# define ZOMBIE_H
# include <string>

class Zombie
{

public:
				Zombie(std::string name, std::string type);
				~Zombie();
	void		announce(void) const;

private:
	std::string	_name;
	std::string	_type;
};

#endif