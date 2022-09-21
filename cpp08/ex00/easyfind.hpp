#ifndef EASYFIND_HPP
# define EASYFIND_HPP
# include <algorithm>

class NotFound : public std::exception
{
public:
	virtual const char *what() const throw()
	{
		return "Value not found";
	}
};

template <template <typename, typename> class T>
typename T<int, std::allocator<int> >::iterator
	easyfind(T<int, std::allocator<int> > &container,
			int value)
{
	typename T<int, std::allocator<int> >::iterator it
		= std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw NotFound();
	else
		return it;
}

template <template <typename, typename> class T>
typename T<int, std::allocator<int> >::const_iterator
	easyfind(const T<int, std::allocator<int> > &container,
			int value)
{
	typename T<int, std::allocator<int> >::const_iterator it
		= std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw NotFound();
	else
		return it;
}

#endif
