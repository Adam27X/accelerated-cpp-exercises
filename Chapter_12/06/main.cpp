#include <iostream>
#include <vector>
#include <fstream>

#include "str.hpp"

int main()
{
	str name;
	std::cout << "Testing empty str: ";
	!name ? std::cout << "Pass." : std::cout << "Fail.";
	std::cout << std::endl;

	name = "test";
	std::cout << "Testing non-empty str: ";
	name ? std::cout << "Pass." : std::cout << "Fail.";
	std::cout << std::endl;

	return 0;
}
