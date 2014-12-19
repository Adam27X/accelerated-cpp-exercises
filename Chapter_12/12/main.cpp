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

	vec<int>::size_type numel = 10;
	vec<int> vec2(numel,10);

	vec2.insert(vec2.begin()+4,vec1.begin(),vec1.end());
	for(vec<int>::iterator i=vec2.begin(); i!=vec2.end(); ++i)
	{
		std::cout << *i << ",";
	}
	std::cout << std::endl;

	str s("test");
	str s2("plz");

	s.insert(s.begin()+2,s2.begin(),s2.end());

	std::cout << s << std::endl;

	return 0;
}
