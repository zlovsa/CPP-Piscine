#ifndef C_HPP
# define C_HPP
# include "Base.hpp"

class C : public Base
{
public:
	C();
	virtual ~C();

private:
	C(C const &other);
	C &operator=(C const &other);
};

#endif
