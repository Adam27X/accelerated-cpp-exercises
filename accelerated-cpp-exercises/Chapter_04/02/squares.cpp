#include <iostream>
#include <iomanip>
#include <ios>

int main()
{
	//max width is the width of "100 10000", which is 9. 3 for i, and 5 for i^2
	std::string::size_type i_width,i_2_width;
	i_width = 3;
	i_2_width = 5;

	for(int i=1; i<101; i++)
	{
		std::cout << std::setw(i_width) << i << " " << std::setw(i_2_width) << i*i << std::endl;
	}

	return 0;
}
