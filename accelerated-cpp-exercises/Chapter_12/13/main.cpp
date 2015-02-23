#include <iostream>
#include <vector>
#include <fstream>
#include <iterator>
#include <string>

#include "str.hpp"

int main()
{
	vec<int> third;
	int myints[] = {1776,7,4};
	third.assign (myints,myints+3);   // assigning from array.

	for(vec<int>::iterator it=third.begin();it!=third.end();++it)
	{
		std::cout << *it << ",";
	}
	std::cout << std::endl;

	return 0;
}
