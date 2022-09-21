#ifndef SQUAD_HPP
# define SQUAD_HPP
# include "ISquad.hpp"
# include "ISpaceMarine.hpp"

class Squad : public ISquad
{
public:
	Squad();
	Squad(Squad const &other);
	Squad &operator=(Squad const &other);
	virtual ~Squad();
	virtual int getCount() const;
	virtual ISpaceMarine *getUnit(int N) const;
	virtual int push(ISpaceMarine *marine);

private:
	typedef struct list{
		ISpaceMarine *marine;
		struct list *next;
	} s_list;
	s_list *_units;
	void _units_delete();
};

#endif
