#include <iostream>
#include <vector>
#include "mutantstack.hpp"

void WriteLine(std::string msg)
{
	std::cout << std::endl
			  << "--- " << msg << " ---" << std::endl;
}

int main()
{
	WriteLine("Subject's main()");
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::stack<int> s(mstack);

	WriteLine("Const iterator");
	MutantStack<int> const msconst(mstack);
	std::cout << msconst << std::endl;

	WriteLine("Reverse iterator");
	std::copy(mstack.rbegin(), mstack.rend(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;

	WriteLine("Const reverse iterator");
	std::copy(msconst.rbegin(), msconst.rend(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;

	return 0;
}