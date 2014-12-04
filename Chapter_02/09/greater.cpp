#include <iostream>

int main()
{
	int x,y;
	std::cout << "Please enter two numbers: ";
	std::cin >> x >> y;
	std::cout << std::endl;

	if(x > y)
	{
		std::cout << x << " is greater than " << y << std::endl;
	}
	else if(y > x)
	{
		std::cout << y << " is greater than " << x << std::endl;
	}
	else
	{
		std::cout << x << " is equivalent to " << y << std::endl;
	}

	return 0;
}
