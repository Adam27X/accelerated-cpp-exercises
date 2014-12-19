#include <iostream>
#include <vector>
#include <fstream>

#include "str.hpp"

int main()
{
	str s = "abba";
	str t = "abcd";

	std::cout << "Testing <: ";
	s < t ? std::cout << "Pass." : std::cout << "Fail";
	std::cout << std::endl;

	std::cout << "Testing <=: ";
	s <= s ? std::cout << "Pass." : std::cout << "Fail";
	std::cout << std::endl;

	std::cout << "Testing >: ";
	t > s ? std::cout << "Pass." : std::cout << "Fail.";
	std::cout << std::endl;

	std::cout << "Testing >=: ";
	t >= t ? std::cout << "Pass." : std::cout << "Fail.";
	std::cout << std::endl;

	return 0;
}
