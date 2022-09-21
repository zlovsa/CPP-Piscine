#ifndef FIXED_HPP
# include <iostream>
# include <cmath>
# define FIXED_HPP
# define FRACTIONAL_BITS 8

class Fixed
{
public:
	Fixed(void);
	Fixed(int const intval);
	Fixed(float const floatval);
	Fixed(Fixed const &other);
	Fixed &operator=(Fixed const &other);
	int getRawBits(void) const;
	void setRawBits(int const raw);
	int toInt(void) const;
	float toFloat(void) const;
	~Fixed();

private:
	int _value;
	static const int _fracBits = FRACTIONAL_BITS;
};

std::ostream &operator<<(std::ostream &o, Fixed const &f);

#endif