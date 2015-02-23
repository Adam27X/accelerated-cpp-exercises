#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>

bool space(char c)
{
	return isspace(c);
}

bool not_space(char c)
{
	return !isspace(c);
}

std::vector<std::string> split(const std::string &s)
{
	typedef std::string::const_iterator iter;
	std::vector<std::string> ret;

	iter i = s.begin();
	while(i != s.end())
	{
		// ignore leading blanks
		i = std::find_if(i,s.end(),not_space);

		// find end of next word
		iter j = std::find_if(i,s.end(),space);

		// copy the characters in [i,j)
		if(i != s.end())
		{
			ret.push_back(std::string(i,j));
		}
		i = j;
	}

	return ret;
}

int main()
{
	std::string s;

	// read and split each line of input
	while(std::getline(std::cin,s))
	{
		std::vector<std::string> v = split(s);

		// write each word in v
		for(std::vector<std::string>::size_type i=0; i!=v.size(); ++i)
		{
			std::cout << v[i] << std::endl;
		}
	}

	return 0;
}
