#include <iostream>
#include <vector>
#include <fstream>
#include <iterator>
#include <string>

#include "str.hpp"

int main()
{
	str test("abcd");
	vec<char> third;
	third.assign(test.begin(),test.end());

	for(vec<char>::iterator it=third.begin();it!=third.end();++it)
	{
		std::cout << *it;
	}
	std::cout << std::endl;

	return 0;
}
