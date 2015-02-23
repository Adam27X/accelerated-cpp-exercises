#include <iostream>
#include <cctype>
#include <algorithm>

#include "str.hpp"

bool space(char c)
{
	return isspace(c);
}

bool not_space(char c)
{
	return !isspace(c);
}

vec<str> split(const str &s)
{
	typedef str::const_iterator iter;
	vec<str> ret;

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
			ret.push_back(str(i,j));
		}
		i = j;
	}

	return ret;
}

int main()
{
	str s;

	// read and split each line of input
	while(getline(std::cin,s))
	{
		vec<str> v = split(s);

		// write each word in v
		for(vec<str>::size_type i=0; i!=v.size(); ++i)
		{
			std::cout << v[i] << std::endl;
		}
	}

	return 0;
}
