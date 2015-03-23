#include <iostream>
#include "funcoverload.hpp"

int main()
{
	std::cout << "f<int*>((int*)0): " << f<int*>((int*)0) << std::endl;
	std::cout << "f<int>((int*)0): " << f<int>((int*)0) << std::endl;

	std::cout << "f(0): " << f(0) << std::endl;
	std::cout << "f((int*)0): " << f((int*)0) << std::endl;

	return 0;
}
