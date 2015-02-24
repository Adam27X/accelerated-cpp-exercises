#include <iostream>
#include <string>
#include <cstdlib>
#include <stdexcept>

#include "stack.hpp"

int main()
{
	try
	{
		Stack<int> intStack;
		Stack<std::string> stringStack;

		intStack.push(7);
		std::cout << "intStack.top(): " << intStack.top() << std::endl;

		stringStack.push("hello");
		std::cout << "stringStack.top(): " << stringStack.top() << std::endl;
		stringStack.pop();
	
		stringStack.pop(); //error
	}
	catch(std::exception const &e)
	{
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}

	return 0;
}
