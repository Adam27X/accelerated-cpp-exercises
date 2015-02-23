#include <iostream>
#include <string>

#include "string_list.hpp"

int main()
{
	std::string arr1[] = {"one","two","three","four"};
	size_t arr1_size = sizeof(arr1)/sizeof(arr1[0]);
	std::cout << "Array size: " << arr1_size << std::endl;

	string_list l(arr1,arr1+arr1_size);

	std::cout << "Testing forward print: " << std::endl;
	l.print_forward();
	std::cout << "Testing backward print: " << std::endl;
	l.print_backward();

	l.push_back("five");
	std::cout << "Testing push_back: ";
	(l.back() == std::string("five")) ? std::cout << "Pass." : std::cout << "Fail: l.back() = " << l.back();
	std::cout << std::endl;
	
	return 0;
}
