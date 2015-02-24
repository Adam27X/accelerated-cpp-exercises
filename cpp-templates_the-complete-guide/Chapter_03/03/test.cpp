#include <iostream>
#include <deque>
#include <cstdlib>

#include "stack.hpp"

int main()
{
	try
	{
		Stack<int> intStack;
		Stack< double,std::deque<double> > dblStack;

		intStack.push(7);
		std::cout << "intStack.top(): " << intStack.top() << std::endl;
		intStack.pop();

		dblStack.push(42);
		std::cout << "dblStack.top(): " << dblStack.top() << std::endl;
		dblStack.pop();

		dblStack.pop(); //error
	}
	catch(std::exception const &ex)
	{
		std::cerr << "Exception: " << ex.what() << std::endl;
	}

	return 0;
}
