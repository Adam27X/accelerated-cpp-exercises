#include <iostream>
#include <vector>
#include <fstream>

#include "str.hpp"

int main()
{
	str test("test333333");

	for(str::iterator i=test.begin()+4; i!=test.end(); ++i)
	{
		std::cout << *i;
	}
	std::cout << std::endl;

	return 0;
}
