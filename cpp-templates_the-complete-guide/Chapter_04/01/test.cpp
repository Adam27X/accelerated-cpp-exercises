#include <iostream>
#include <string>
#include <cstdlib>

#include "stack.hpp"

int main()
{
	try
	{
		Stack<int,20> int20Stack;
		Stack<int,40> int40Stack;
		Stack<std::string,40> stringStack;

		int20Stack.push(7);
		std::cout << "int20Stack.top(): " << int20Stack.top() << std::endl;

		stringStack.push("hello");
		std::cout << stringStack.top() << std::endl;
		stringStack.pop();

		stringStack.pop(); //error
	}
	catch (std::exception const &ex)
	{
		std::cerr << "Exception: " << ex.what() << std::endl;
	}

	return 0;
}
