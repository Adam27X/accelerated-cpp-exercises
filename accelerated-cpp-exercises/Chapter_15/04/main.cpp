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
	picture q = frame(p,'1','2','3');
	picture r = hcat(p,q);
	picture s = vcat(q,r);
	picture t = frame(hcat(s,vcat(r,q)));
	t.reframe('4','5','6');

	std::cout << t; //TODO: figure out why this segfaults if << std::endl is appended
	std::cout << std::endl;

	return 0;
}
