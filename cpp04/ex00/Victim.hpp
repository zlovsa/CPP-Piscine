#ifndef VICTIM_HPP
# define VICTIM_HPP
# include <string>

class Victim
{
public:
	Victim(std::string const &name);
	Victim(Victim const &other);
	Victim &operator=(Victim const &other);
	virtual ~Victim();
	std::string const &getName() const;
	virtual void getPolymorphed() const;

protected:
	Victim();

private:
	std::string _name;
};

std::ostream &operator<<(std::ostream &o, Victim const &v);

#endif