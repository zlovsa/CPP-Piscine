#ifndef SPAN_HPP
# define SPAN_HPP
# include <string>
# include <vector>

class Span
{
public:
	class NotEnoughRoom : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return "Not enough room to add number";
		}
	};
	class NoSpanToFind : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return "Not enough numbers to find span";
		}
	};
	Span(unsigned int N);
	Span(Span const &other);
	Span &operator=(Span const &other);
	virtual ~Span();
	void addNumber(int number);
	template <class Iter>
	void addRange(Iter begin, Iter end);
	unsigned int shortestSpan() const;
	unsigned int longestSpan() const;
	std::vector<int> const &getVec() const;

private:
	Span();
	unsigned int _capacity;
	std::vector<int> _items;
};

std::ostream &operator<<(std::ostream &o, Span const &sp);

template <class Iter>
void Span::addRange(Iter begin, Iter end)
{
	if (_items.size() + end - begin > _capacity)
		throw Span::NotEnoughRoom();
	else
		std::copy(begin, end, std::back_inserter(_items));
}

#endif