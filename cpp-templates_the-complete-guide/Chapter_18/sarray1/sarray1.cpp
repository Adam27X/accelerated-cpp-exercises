#include <iostream>
#include <cstdlib>
#include "sarray1.hpp"
#include "sarrayops1.hpp"

int main()
{
	SArray<double> x(10), y(10);

	for(int i=0; i<10; i++)
	{
		x[i] = rand() % 100;
		y[i] = rand() % 100;
	}

	std::cout << "x = [ ";
	for(int i=0; i<10; i++)
	{
		std::cout << x[i] << " ";
	}
	std::cout << "]" << std::endl;
	
	std::cout << "y = [ ";
	for(int i=0; i<10; i++)
	{
		std::cout << y[i] << " ";
	}
	std::cout << "]" << std::endl;

	x = 1.2*x + x*y;

	std::cout << "1.2*x + x*y = [ ";
	for(int i=0; i<10; i++)
	{
		std::cout << x[i] << " ";
	}
	std::cout << "]" << std::endl;

	return 0;
}
