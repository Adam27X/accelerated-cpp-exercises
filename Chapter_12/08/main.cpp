#include <iostream>
#include <vector>
#include <fstream>
#include <string>

#include "str.hpp"

int main()
{
	str test("test");
	getline(std::cin,test);

	std::cout << test << std::endl;

	std::string test2("test");
	std::getline(std::cin,test2);
	std::cout << test2 << std::endl;

	return 0;
}
