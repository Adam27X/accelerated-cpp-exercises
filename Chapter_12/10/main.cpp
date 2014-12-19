#include <iostream>
#include <vector>
#include <fstream>
#include <iterator>
#include <string>

#include "str.hpp"

int main()
{
	std::vector<int> vec1;
	for(int i=0; i<5; i++)
	{
		vec1.push_back(2*i + 1);
	}

	vec<int> vec2(vec1.begin(),vec1.end());
	std::cout << "[" << vec2[0];
	for(int i=1; i<vec2.size(); i++)
	{
		std::cout << "," << vec2[i];
	}
	std::cout << "]" << std::endl;

	str abc("abcdefghijklmnopqrstuvwxyz");
	str test(abc.begin(),abc.end());

	std::cout << test << std::endl;

	return 0;
}
