#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include <string>
# include "ICharacter.hpp"

class Character : public ICharacter
{
public:
	Character();
	Character(std::string const &name);
	Character(Character const &other);
	Character &operator=(Character const &other);
	virtual ~Character();
	virtual std::string const &getName() const;
	virtual void equip(AMateria *m);
	virtual void unequip(int idx);
	virtual void use(int idx, ICharacter &target);
	void Announce();

private:
	std::string _name;
	AMateria *_materias[4];
	int _materiacount;
	void _materias_delete();
	void _materias_init();
};

#endif
