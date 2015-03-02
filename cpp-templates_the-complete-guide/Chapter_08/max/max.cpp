#include <iostream>

template <typename T>
inline T const& max(const T &a, const T &b)
{
	return a < b ? b : a;
}

int main()
{
	std::cout << "max<double>(1.0,-3.0): " << max<double>(1.0,-3.0) << std::endl; //explicitly specify template argument
	std::cout << "max(1.0,-3.0): " << max(1.0,-3.0) << std::endl; //template argument deduced as double
	std::cout << "max<int>(1.0,3.0): " << max<int>(1.0,3.0) << std::endl; //explicit <int> inhibits deduction of double

	return 0;
}
