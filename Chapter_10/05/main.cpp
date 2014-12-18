#include <iostream>
#include <string>

#include "string_list.hpp"

int main()
{
	std::string arr1[] = {"one","two","three","four"};
	size_t arr1_size = sizeof(arr1)/sizeof(arr1[0]);
	std::cout << "Array size: " << arr1_size << std::endl;

	string_list l(arr1,arr1+arr1_size);

	std::cout << "Testing dereference: " << std::endl;
	node it = l.begin();
	std::cout << *it << std::endl;

	std::cout << "Testing increment: " << std::endl;
	++it;
	++it;
	std::cout << *it << std::endl;

	std::cout << "Testing decrement: " << std::endl;
	--it;
	std::cout << *it << std::endl;

	std::cout << "Testing inequality: " << std::endl;
	node it2 = l.begin();
	std::cout << "it1 != it2: " << (it != it2) << std::endl;
	node it3 = l.begin();
	std::cout << "it2 == it3: " << (it2 == it3) << std::endl;

	std::cout << "Testing end derefence: " << std::endl;
	node it4 = l.end();
	std::cout << *it4 << std::endl;
	++it; ++it;
	std::cout << "it == it4 " << (it == it4) << std::endl;
	
	return 0;
}
