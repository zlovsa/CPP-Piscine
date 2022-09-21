#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP
# include <stack>

template<typename T>
class MutantStack : public std::stack<T>
{
public:
	MutantStack();
	MutantStack(MutantStack const &other);
	MutantStack &operator=(MutantStack const &other);
	virtual ~MutantStack();

	typedef
		typename std::stack<T>::container_type::iterator
	iterator;
	iterator begin();
	iterator end();

	typedef
		typename std::stack<T>::container_type::const_iterator
	const_iterator;
	const_iterator begin() const;
	const_iterator end() const;

	typedef
		typename std::stack<T>::container_type::reverse_iterator
	reverse_iterator;
	reverse_iterator rbegin();
	reverse_iterator rend();

	typedef
		typename std::stack<T>::container_type::const_reverse_iterator
	const_reverse_iterator;
	const_reverse_iterator rbegin() const;
	const_reverse_iterator rend() const;
};

template <typename T>
std::ostream &operator<<(std::ostream &o, MutantStack<T> const &st)
{
	std::copy(st.begin(), st.end(), std::ostream_iterator<T>(o, " "));
	return o;
}

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>()
{
}

template <typename T>
MutantStack<T>::MutantStack(MutantStack const &other) : std::stack<T>(other)
{
}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(MutantStack const &other)
{
	if (this != &other)
		std::stack<T>::operator=(other);
	return *this;
}

template <typename T>
MutantStack<T>::~MutantStack()
{
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return this->c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return this->c.end();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const
{
	return this->c.begin();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const
{
	return this->c.end();
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin()
{
	return this->c.rbegin();
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend()
{
	return this->c.rend();
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rbegin() const
{
	return this->c.rbegin();
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rend() const
{
	return this->c.rend();
}

#endif