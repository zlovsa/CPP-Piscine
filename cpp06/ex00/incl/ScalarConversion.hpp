#ifndef SCALARCONVERSION_HPP
# define SCALARCONVERSION_HPP
# include <string>

class ScalarConversion
{
public:
	class ConversionNotPossible : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return "Conversion to that type not possible";
		}
	};
	ScalarConversion(std::string const &arg);
	~ScalarConversion();
	std::string const &getLastArgument() const;
	bool charPossible() const;
	char toChar() const;
	bool intPossible() const;
	int toInt() const;
	bool floatPossible() const;
	float toFloat() const;
	bool doublePossible() const;
	double toDouble() const;
	void report() const;

private:
	ScalarConversion();
	ScalarConversion(ScalarConversion const &other);
	ScalarConversion &operator=(ScalarConversion const &other);

	bool char_try_parse(std::string arg, char *c);
	void convert_from_char();
	bool int_try_parse(std::string arg, int *i);
	void convert_from_int();
	bool float_try_parse(std::string arg, float *f);
	void convert_from_float();
	bool double_try_parse(std::string arg, double *d);
	void convert_from_double();
	std::string float_to_string(float f) const;
	std::string double_to_string(double d) const;

	std::string const _arg;
	bool _char_possible;
	char _char_val;
	bool _int_possible;
	int _int_val;
	bool _float_possible;
	float _float_val;
	bool _double_possible;
	double _double_val;
};

#endif
