#include <iostream>

#include "sqrt4.hpp"

int main()
{
	std::cout << "Sqrt<16>::result = " << Sqrt<16>::result << "\n";
	std::cout << "Sqrt<25>::result = " << Sqrt<25>::result << "\n";
	std::cout << "Sqrt<42>::result = " << Sqrt<42>::result << "\n";
	std::cout << "Sqrt<1>::result = " << Sqrt<1>::result << "\n";

	return 0;
}
