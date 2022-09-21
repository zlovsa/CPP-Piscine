#ifndef ITER_HPP
# define ITER_HPP
# include <iostream>

template <typename T>
void iter(T *array, size_t length, void (*func)(T &x))
{
	for (size_t i = 0; i < length; i++)
		func(array[i]);
}

template <typename T>
void print(T &x)
{
	std::cout << x << std::endl;
}

template <typename T>
void inc(T &x)
{
	x++;
}

#endif
