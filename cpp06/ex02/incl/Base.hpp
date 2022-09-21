#ifndef BASE_HPP
# define BASE_HPP

class Base
{
public:
	Base();
	virtual ~Base();

private:
	Base(Base const &other);
	Base &operator=(Base const &other);
};

#endif
