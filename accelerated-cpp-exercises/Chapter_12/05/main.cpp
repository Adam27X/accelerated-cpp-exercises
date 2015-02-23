#include <iostream>
#include <vector>
#include <fstream>

#include "str.hpp"

int main()
{
	str name;
	std::cout << "Enter your name: ";
	std::cin >> name;

	const str greeting = "Hello, " + name + "!";	
	std::cout << greeting << std::endl;

	return 0;
}
