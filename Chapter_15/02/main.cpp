#include <iostream>
#include <vector>
#include <string>

#include "picture.hpp"

int main()
{
	std::vector<std::string> test;
	test.push_back("this is a test....");
	test.push_back("...you know");
	
	picture p = test; 
	picture q = frame(p);
	picture r = hcat(p,q);
	picture s = vcat(q,r);

	std::cout << frame(hcat(s,vcat(r,q))); //TODO: figure out why this segfaults if << std::endl is appended
	std::cout << std::endl;

	return 0;
}
