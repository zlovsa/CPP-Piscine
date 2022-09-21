#ifndef AMATERIA_HPP
# define AMATERIA_HPP
# include <string>

class ICharacter;

class AMateria
{
private:
	std::string _type;
	unsigned int _xp;
	AMateria();

public:
	AMateria(AMateria const &other);
	AMateria(std::string const &type);
	AMateria &operator=(AMateria const &other);
	virtual ~AMateria();

	std::string const &getType() const; //Returns the materia type
	unsigned int getXP() const;			//Returns the Materia's XP

	virtual AMateria *clone() const = 0;
	virtual void use(ICharacter &target);
};

#endif
