#ifndef FIXED_HPP
#define FIXED_HPP
#define FRACTIONAL_BITS 8

class Fixed
{
public:
	Fixed(void);
	Fixed(const Fixed &other);
	Fixed &operator=(Fixed const &other);
	int getRawBits(void) const;
	void setRawBits(int const raw);
	~Fixed();

private:
	int _value;
	static const int _fracBits = FRACTIONAL_BITS;
};

#endif