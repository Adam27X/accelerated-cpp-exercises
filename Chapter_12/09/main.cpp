#include <iostream>
#include <vector>
#include <fstream>
#include <iterator>

#include "str.hpp"

int main()
{
	str test("test");
	getline(std::cin,test);

	std::ostream_iterator<char> osi(std::cout);
	osi << test;

	return 0;
}
