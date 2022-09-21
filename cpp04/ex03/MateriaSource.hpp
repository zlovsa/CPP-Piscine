#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP
# include <string>
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
public:
	MateriaSource();
	MateriaSource(MateriaSource const &other);
	MateriaSource &operator=(MateriaSource const &other);
	virtual ~MateriaSource();
	virtual void learnMateria(AMateria *m);
	virtual AMateria *createMateria(std::string const &type);

private:
	AMateria *_materias[4];
	int _materiacount;
};

#endif
