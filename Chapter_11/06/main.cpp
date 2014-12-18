#include <iostream>

#include "vec.hpp"

int main()
{
	vec<int> test(5,2);
	test.push_back(6);
	test[3] = 3;
	std::cout << "Testing vec::size(): ";
	test.size() == 6 ? std::cout << "Pass." : std::cout << "Fail.";
	std::cout << std::endl;

	std::cout << "Testing iterators: " << std::endl;
	for(vec<int>::const_iterator i=test.begin(); i!=test.end(); i++)
	{
		if(i == test.begin())
		{
			std::cout << "[" << *i;
		}
		else
		{
			std::cout << "," << *i;
		}
	}
	std::cout << "]" << std::endl;

	std::cout << "Testing erase: ";
	test.erase(test.begin());
	test[2] == 3 ? std::cout << "Pass." : std::cout << "Fail.";
	std::cout << std::endl;

	std::cout << "Testing clear: ";
	test.clear();
	test.size() == 0 ? std::cout << "Pass." : std::cout << "Fail.";
	std::cout << std::endl;

	return 0;
}
