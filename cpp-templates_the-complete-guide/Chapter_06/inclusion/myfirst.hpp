#include <iostream>
#include <typeinfo>

template <typename T>
void print_typeof(T const &x)
{
	std::cout << typeid(x).name() << std::endl;
}
