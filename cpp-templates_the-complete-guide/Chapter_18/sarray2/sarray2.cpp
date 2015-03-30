#include <iostream>
#include <cstdlib>
#include "sarray2.hpp"
#include "sarrayops2.hpp"

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

	//process x = 1.2*x + x*y
	SArray<double> tmp(x);
	tmp *= y;
	x *= 1.2;
	x += tmp;

	std::cout << "1.2*x + x*y = [ ";
	for(int i=0; i<10; i++)
	{
		std::cout << x[i] << " ";
	}
	std::cout << "]" << std::endl;

	return 0;
}
