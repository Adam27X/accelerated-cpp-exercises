//SFINAE: Substitution Failure Is Not An Error 
#include <iostream>

template <int N> 
int g()
{
	return N;
}

template <int *P>
int g()
{
	return *P;
}

int main()
{
	std::cout << "g<1>(): " << g<1>() << std::endl; //1 cannot be bound to int * parameter, but SFINAE makes this result ok. 1 can be bound to int, so this overloading is valid.

	return 0;
}
