#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include <vector>

int main()
{
	std::map<int, std::string> m;
	m.insert(std::make_pair(1,std::string("one")));
	m.insert(std::make_pair(2,std::string("two")));
	m.insert(std::make_pair(3,std::string("three")));

	std::vector< std::pair<int,std::string> > test;
	std::copy(m.begin(),m.end(),std::back_inserter(test));

	std::cout << "Test: " << test[0].first << " -> " << test[0].second << std::endl;

	std::copy(test.begin(),test.end(),std::inserter(m,m.end())); //back_inserter wouldn't work here

	std::cout << "Test 2: " << std::endl;
	for(std::map<int,std::string>::const_iterator i=m.begin();i!=m.end();++i)
	{
		std::cout << i->first << " -> " << i->second << std::endl;
	}

	return 0;
}
