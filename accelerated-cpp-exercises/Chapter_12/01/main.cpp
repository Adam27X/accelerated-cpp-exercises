#include <iostream>
#include <vector>

#include "str.hpp"

int main()
{
	str test = "Hello world!";
	std::cout << test << std::endl;
	str test2("Hello world 2");
	std::cout << test2 << std::endl;
	str test3(3,'3');
	std::cout << test3 << std::endl;
	str test4;

	std::cout << "Enter a test string: ";
	std::cin >> test4;
	std::cout << test4 << std::endl;

	str test5 = test+test2;
	std::cout << test5 << std::endl;
	test5 += test3;
	std::cout << test5 << std::endl;

	str test6("weeeee");
	for(str::iterator i=test6.begin();i!=test6.end();++i)
	{
		std::cout << *i;
	}
	std::cout << std::endl;

	return 0;
}
