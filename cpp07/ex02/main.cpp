#include <iostream>
#include "Array.hpp"

template <typename T>
void print(Array<T> &a)
{
	for (unsigned int i = 0; i < a.size(); i++)
		std::cout << a[i] << std::endl;
	std::cout << "Size: " << a.size() << std::endl;
}

int main(void)
{
	std::cout << "Empty int array a():" << std::endl;
	Array<int> a;
	print(a);

	std::cout << std::endl
			  << "4-float array b(4):" << std::endl;
	Array<float> b(4);
	b[0] = 0.5f;
	b[1] = -13.01f;
	b[2] = 7.6f;
	b[3] = 42;
	print(b);

	std::cout << std::endl
			  << "Out of bound exception, b[5]=8;" << std::endl;
	try
	{
		b[5] = 8;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl
			  << "Copy constructor and change. Copied c(b); c[1]=123.456f;" << std::endl;
	Array<float> c(b);
	c[1] = 123.456f;
	print(c);
	std::cout << "Original:" << std::endl;
	print(b);

	std::cout << std::endl
			  << "Assignment operator and change. New array d(3):" << std::endl;
	Array<int> d(3);
	d[0] = 8;
	d[1] = 13;
	d[2] = 5;
	print(d);
	std::cout << "Assignment a = d; a[2]=-80;" << std::endl;
	a = d;
	a[2] = -80;
	print(a);

	std::cout << std::endl
			  << "Const overload of operator[]. const array e(a); e[2]" << std::endl;
	const Array<int> e(a);
	std::cout << e[2] << std::endl;

	return 0;
}
