#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	std::cout << "Enter a set of integers: ";
	std::vector<int> data;
	int x;
	while(std::cin >> x)
	{
		data.push_back(x);
	}
	std::cout << std::endl;

	typedef std::vector<int>::size_type vec_sz;
	vec_sz size = data.size();
	if(size == 0)
	{
		std::cout << "Error: Invalid input." << std::endl; //std::cerr is probably more appropriate, but the book hasn't covered that yet
		return 1;
	}	

	std::sort(data.begin(),data.end(),std::greater<int>()); //Sort in descending order

	std::cout << "First quartile:";
	for(vec_sz i=0; i<size/4; ++i)
	{
		std::cout << " " << data[i];
	}
	std::cout << std::endl << "Second quartile:";
	for(vec_sz i=size/4; i<size/2; ++i)
	{
		std::cout << " " << data[i];
	}
	std::cout << std::endl << "Third quartile:";
	for(vec_sz i=size/2; i<3*size/4; ++i)
	{
		std::cout << " " << data[i];
	}
	std::cout << std::endl << "Fourth quartile:";
	for(vec_sz i=3*size/4; i<size; ++i)
	{
		std::cout << " " << data[i];
	}
	std::cout << std::endl;

	return 0;
}
