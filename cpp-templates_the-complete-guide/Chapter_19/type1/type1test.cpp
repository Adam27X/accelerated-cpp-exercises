#include <iostream>
#include "type1.hpp"

template <typename T>
void test(T const &t)
{
	if(IsFundaT<T>::Yes)
	{
		std::cout << "T is a fundamental type" << std::endl;
	}
	else
	{
		std::cout << "T is not a fundamental type" << std::endl;
	}
}

class MyType
{ };

int main()
{
	std::cout << "7: " << std::endl;
	test(7);
	std::cout << "MyType: " << std::endl;
	test(MyType());

	return 0;
}
