#include <iostream>

#include "stackdecl.hpp"
#include "stackassign.hpp"

int main()
{
	Stack<int> intStack;
	intStack.push(7);

	Stack<float> floatStack;
	floatStack.push(7.77f);

	floatStack = intStack;

	std::cout << "floatStack.top(): " << floatStack.top() << std::endl;

	return 0;
}
