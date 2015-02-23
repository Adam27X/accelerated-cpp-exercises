#include <iostream>
#include <iomanip>
#include <ios>
#include <stdexcept>

void get_width(std::string::size_type &i_width, std::string::size_type &i_2_width, double end, const std::string::size_type precision)
{
	double end_squared = end*end;

	//find number of digits in end
	i_width = precision;
	while(end > 1)
	{
		end /= 10;
		i_width++;
	}

	i_2_width = precision;
	while(end_squared > 1)
	{
		end_squared /= 10;
		i_2_width++;
	}
}

int main()
{
	//max width is the width of "100 10000", which is 9. 3 for i, and 5 for i^2
	std::cout << "Enter the range [x,y) of squared numbers that you would like to see: ";
	double start,end;
	std::cin >> start >> end;
	if(start > end)
	{
		throw std::range_error("start must be less than or equal to end of range!");
	}

	std::string::size_type i_width,i_2_width;
	const std::string::size_type precision = 7; //Use 3 digits of precision
	get_width(i_width,i_2_width,end,precision);

	std::streamsize prec = std::cout.precision();
	std::cout << std::setprecision(precision);
	for(double i=start; i<end; i++)
	{
		std::cout << std::setw(i_width) << i << " " << std::setw(i_2_width) << i*i << std::endl;
	}
	std::cout << std::setprecision(prec);

	return 0;
}
