#include <iostream>
#include "t.hpp"

int main()
{
	S<int> s;
	helper(&s);
	s.f(); //second point of instantiation of S::f

	std::cout << "Instantiation successful." << std::endl;

	return 0;
}
