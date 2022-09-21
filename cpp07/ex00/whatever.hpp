#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T>
void swap(T &a, T &b)
{
	T t = a;
	a = b;
	b = t;
}

template <typename T>
T const &min(T const &a, T const &b)
{
	if (a < b)
		return a;
	return b;
}

template <typename T>
T const &max(T const &a, T const &b)
{
	if (a > b)
		return a;
	return b;
}

#endif
