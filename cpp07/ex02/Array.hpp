#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <iostream>

template <typename T>
class Array
{
public:
	class IndexOutOfBoundException : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return "Index out of bound";
		}
	};
	Array();
	Array(unsigned int n);
	Array(Array<T> const &other);
	Array<T> &operator=(Array<T> const &other);
	~Array();
	T &operator[](unsigned int index);
	T const &operator[](unsigned int index) const;
	unsigned int size() const;

private:
	T *_items;
	unsigned int _size;
	void _items_delete();
};

template <typename T>
Array<T>::Array() : _items(0), _size(0)
{
}

template <typename T>
Array<T>::Array(unsigned int n) : _size(n)
{
	_items = new T[n]();
}

template <typename T>
Array<T>::Array(Array<T> const &other) : _items(0), _size(0)
{
	*this = other;
}

template <typename T>
Array<T> &Array<T>::operator=(Array<T> const &other)
{
	if (this == &other)
		return *this;
	_items_delete();
	_size = other._size;
	_items = new T[_size]();
	for (unsigned int i = 0; i < _size; i++)
		_items[i] = other._items[i];
	return *this;
}

template <typename T>
Array<T>::~Array()
{
	_items_delete();
}

template <typename T>
void Array<T>::_items_delete()
{
	_size = 0;
	delete[] _items;
	_items = 0;
}

template <typename T>
T &Array<T>::operator[](unsigned int index)
{
	if (index < _size)
		return _items[index];
	else
		throw Array<T>::IndexOutOfBoundException();
}

template <typename T>
T const &Array<T>::operator[](unsigned int index) const
{
	if (index < _size)
		return _items[index];
	else
		throw Array<T>::IndexOutOfBoundException();
}

template <typename T>
unsigned int Array<T>::size() const
{
	return _size;
}

#endif
