#include "ScalarConversion.hpp"
#include <iostream>
#include <sstream>

ScalarConversion::ScalarConversion(std::string const &arg) :
	_arg(arg),
	_char_possible(false),
	_int_possible(false),
	_float_possible(false),
	_double_possible(false)
{
	if (char_try_parse(arg, &_char_val))
		convert_from_char();
	else if(int_try_parse(arg, &_int_val))
		convert_from_int();
	else if (float_try_parse(arg, &_float_val))
		convert_from_float();
	else if (double_try_parse(arg, &_double_val))
		convert_from_double();
}

ScalarConversion::~ScalarConversion()
{
}

void ScalarConversion::convert_from_char()
{
	_char_possible = true;
	_int_possible = true;
	_int_val = static_cast<int>(_char_val);
	_float_possible = true;
	_float_val = static_cast<float>(_char_val);
	_double_possible = true;
	_double_val = static_cast<double>(_char_val);
}

void ScalarConversion::convert_from_int()
{
	_int_possible = true;
	if (std::numeric_limits<char>::lowest() <= _int_val
		&& _int_val <= std::numeric_limits<char>::max())
	{
		_char_possible = true;
		_char_val = static_cast<char>(_int_val);
	}
	_float_possible = true;
	_float_val = static_cast<float>(_int_val);
	_double_possible = true;
	_double_val = static_cast<double>(_int_val);
}

void ScalarConversion::convert_from_float()
{
	_float_possible = true;
	if (std::numeric_limits<char>::lowest() <= _float_val 
		&& _float_val <= std::numeric_limits<char>::max())
	{
		_char_possible = true;
		_char_val = static_cast<char>(_float_val);
	}
	if (std::numeric_limits<int>::lowest() <= _float_val
		&& _float_val <= std::numeric_limits<int>::max())
	{
		_int_possible = true;
		_int_val = static_cast<int>(_float_val);
	}
	_double_possible = true;
	_double_val = static_cast<double>(_float_val);
}

void ScalarConversion::convert_from_double()
{
	_double_possible = true;
	if (std::numeric_limits<char>::lowest() <= _double_val
		&& _double_val <= std::numeric_limits<char>::max())
	{
		_char_possible = true;
		_char_val = static_cast<char>(_double_val);
	}
	if (std::numeric_limits<int>::lowest() <= _double_val
		&& _double_val <= std::numeric_limits<int>::max())
	{
		_int_possible = true;
		_int_val = static_cast<int>(_double_val);
	}
	if ((std::numeric_limits<float>::lowest() <= _double_val
		&& _double_val <= std::numeric_limits<float>::max())
		|| isnan(_double_val)
		|| _double_val==std::numeric_limits<double>::infinity()
		|| _double_val==-std::numeric_limits<double>::infinity())
	{
		_float_possible = true;
		_float_val = static_cast<float>(_double_val);
	}
}

std::string const &ScalarConversion::getLastArgument() const
{
	return _arg;
}

bool ScalarConversion::charPossible() const
{
	return _char_possible;
}

char ScalarConversion::toChar() const
{
	if(_char_possible)
		return _char_val;
	else
		throw ScalarConversion::ConversionNotPossible();
}

bool ScalarConversion::intPossible() const
{
	return _int_possible;
}

int ScalarConversion::toInt() const
{
	if (_int_possible)
		return _int_val;
	else
		throw ScalarConversion::ConversionNotPossible();
}

bool ScalarConversion::floatPossible() const
{
	return _float_possible;
}

float ScalarConversion::toFloat() const
{
	if (_float_possible)
		return _float_val;
	else
		throw ScalarConversion::ConversionNotPossible();
}

bool ScalarConversion::doublePossible() const
{
	return _double_possible;
}

double ScalarConversion::toDouble() const
{
	if (_double_possible)
		return _double_val;
	else
		throw ScalarConversion::ConversionNotPossible();
}

void ScalarConversion::report() const
{
	std::cout << "char: ";
	if (_char_possible)
	{
		if (std::isprint(_char_val))
			std::cout << "'" << _char_val << "'" << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
	}
	else
		std::cout << "impossible" << std::endl;
	std::cout << "int: ";
	if (_int_possible)
		std::cout << _int_val << std::endl;
	else
		std::cout << "impossible" << std::endl;
	std::cout << "float: ";
	if (_float_possible)
		std::cout << float_to_string(_float_val) << std::endl;
	else
		std::cout << "impossible" << std::endl;
	std::cout << "double: ";
	if (_double_possible)
		std::cout << double_to_string(_double_val) << std::endl;
	else
		std::cout << "impossible" << std::endl;
}

bool ScalarConversion::char_try_parse(std::string arg, char *c)
{
	if (arg.length() == 1 && !std::isdigit(arg.at(0)))
	{
		*c = arg.at(0);
		return true;
	}
	if (arg.length() == 3 && arg.at(0) == '\'' && arg.at(0) == arg.at(2))
	{
		*c = arg.at(1);
		return true;
	}
	return false;
}

bool ScalarConversion::int_try_parse(std::string arg, int *i)
{
	try
	{
		size_t pos;
		*i = std::stoi(arg, &pos);
		if (pos != arg.length())
			return false;
	}
	catch (...)
	{
		return false;
	}
	return true;
}

bool ScalarConversion::float_try_parse(std::string arg, float *f)
{
	try
	{
		size_t pos;
		*f = std::stof(arg, &pos);
		if (pos != arg.length() - 1 || arg.at(pos) != 'f')
			return false;
	}
	catch (...)
	{
		return false;
	}
	return true;
}

bool ScalarConversion::double_try_parse(std::string arg, double *d)
{
	try
	{
		size_t pos;
		*d = std::stod(arg, &pos);
		if (pos != arg.length())
			return false;
	}
	catch (...)
	{
		return false;
	}
	return true;
}

std::string ScalarConversion::float_to_string(float f) const
{
	std::stringstream ss;
	ss << f;
	std::string str;
	ss >> str;
	if (str.find('n') == std::string::npos
		&& str.find('.') == std::string::npos)
		str.append(".0");
	str.append("f");
	return str;
}

std::string ScalarConversion::double_to_string(double d) const
{
	std::stringstream ss;
	ss << d;
	std::string str;
	ss >> str;
	if (str.find('n') == std::string::npos
		&& str.find('.') == std::string::npos)
		str.append(".0");
	return str;
}
