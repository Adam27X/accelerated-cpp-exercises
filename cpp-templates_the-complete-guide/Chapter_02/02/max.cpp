#include <iostream>
#include <string>

//maximum of two int values
inline int const& max(int const &a, int const &b)
{
	return a<b ? b : a;
}

//maximum of two values of any type
template <typename T>
inline T const& max(T const &a, T const &b)
{
	return a<b ? b : a;
}

//maximum of three values of any type
template <typename T>
inline T const& max(T const &a, T const &b, T const &c)
{
	return max(max(a,b),c);
}

int main()
{
	std::cout << "max(7,42,68): " << ::max(7,42,68) << std::endl; //calls the template for three arguments
	std::cout << "max(7.0,42.0): " << ::max(7.0,42.0) << std::endl; //calls max<double> by argument deduction
	std::cout << "max('a','b'): " << ::max('a','b') << std::endl; //calls max<char> by argument deduction
	std::cout << "max(7,42): " << ::max(7,42) << std::endl; //calls the nontemplate for two ints
	std::cout << "max<>(7,42): " << ::max<>(7,42) << std::endl; //calls max<int> by argument deduction
	std::cout << "max<double>(7,42): " << ::max<double>(7,42) << std::endl; //calls max<double> without argument deduction
	std::cout << "max('a',42.7): " << ::max('a',42.7) << std::endl; //calls the nontemplate for two ints

	return 0;
}
