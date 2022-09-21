#include <iostream>
#include <algorithm>
#include <numeric>
#include <iterator>
#include "span.hpp"

Span::Span(unsigned int N) : _capacity(N)
{
}

Span::Span(const Span &other)
{
	*this = other;
}

Span &Span::operator=(Span const &other)
{
	if (this == &other)
		return *this;
	_capacity = other._capacity;
	_items = other._items;
	return *this;
}

Span::~Span()
{
}

void Span::addNumber(int number)
{
	if (_items.size() < _capacity)
		_items.push_back(number);
	else
		throw Span::NotEnoughRoom();
}

static bool abs_compare(int a, int b)
{
	return (std::abs(a) < std::abs(b));
}

unsigned int Span::shortestSpan() const
{
	if (_items.size() > 1)
	{
		std::vector<int> diff;
		std::adjacent_difference(_items.begin(), _items.end(),
								 std::back_inserter(diff));
		int span = *std::min_element(std::next(diff.begin()), diff.end(),
									 abs_compare);
		return static_cast<unsigned int>(std::abs(span));
	}
	else
		throw Span::NoSpanToFind();
}

unsigned int Span::longestSpan() const
{
	if (_items.size() > 1)
	{
		std::vector<int> diff;
		std::adjacent_difference(_items.begin(), _items.end(),
								 std::back_inserter(diff));
		int span = *std::max_element(std::next(diff.begin()), diff.end(),
									 abs_compare);
		return static_cast<unsigned int>(std::abs(span));
	}
	else
		throw Span::NoSpanToFind();
}

std::vector<int> const &Span::getVec() const
{
	return _items;
}

std::ostream &operator<<(std::ostream &o, Span const &sp)
{
	std::vector<int> v = sp.getVec();
	std::copy(v.begin(), v.end(), std::ostream_iterator<int>(o, " "));
	return o;
}