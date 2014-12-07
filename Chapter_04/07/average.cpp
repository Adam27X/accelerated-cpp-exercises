#include <iostream>
#include <vector>
#include <stdexcept>

double mean(const std::vector<double> &d)
{
	double sum = 0;
	if(d.size() == 0)
	{
		throw std::domain_error("Invalid input.");
	}
	for(std::vector<double>::size_type i=0; i<d.size(); i++)
	{
		sum += d[i];
	}	
	return sum/(double)d.size();
}

int main()
{
	std::cout << "Please enter a series of doubles: " << std::endl;
	std::vector<double> data;
	double x;
	while(std::cin >> x)
	{
		data.push_back(x);
	}

	//Calculate the average
	try
	{
		std::cout << "The average is: " << mean(data) << std::endl;
	}
	catch(std::domain_error e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
