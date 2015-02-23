#include <iostream>
#include <string>
#include <cstring>

//maximum of two values of any type
template <typename T>
inline T const& max(T const &a, T const &b)
{
	return a<b ? b : a;
}

//maximum of two pointers
template <typename T>
inline T* const& max(T* const &a, T* const &b)
{
	return *a < *b ? b : a;
}

//maximum of two C-strings
inline char const* const& max(char const* const &a, char const* const &b)
{
	return std::strcmp(a,b) < 0 ? b : a;
}

int main()
{
	int a=7;
	int b=42;
	std::cout << "max(a,b): " << ::max(a,b) << std::endl; //max for two values of type int

	std::string s="hey";
	std::string t="you";
	std::cout << "max(s,t): " << ::max(s,t) << std::endl; //max for two values of type std::string

	int *p1 = &b;
	int *p2 = &a;
	std::cout << "max(p1,p2): " << *::max(p1,p2) << std::endl; //max for two pointers

	char const *s1 = "David";
	char const *s2 = "Nico";
	std::cout << "max(s1,s2): " << ::max(s1,s2) << std::endl; //max for two C-strings

	return 0;
}
