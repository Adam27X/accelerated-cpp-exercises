#include <iostream>
#include <vector>
#include <string>

#include "picture.hpp"

int main()
{
	std::vector<std::string> test;
	test.push_back("this is a test....");
	test.push_back("...you know");
	test.push_back("for sure");
	
	picture p = test; 
	picture q = vcat(vcat(p,p),p);
	picture r = hcat(p,q);

	std::cout << r; //TODO: figure out why this segfaults if << std::endl is appended
	std::cout << std::endl;

	return 0;
}
