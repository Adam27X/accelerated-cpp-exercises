#include <iostream>
#include <cctype>

#include "str.hpp"
#include "vec.hpp"

vec<str> split(const str &s)
{
	vec<str> ret;
	typedef str::size_type string_size;
	string_size i=0;

	// invariant: we have processed characters [original value of i,i)
	while(i != s.size())
	{
		// ignore leading blanks
		// invariant: characters in range [original i,current i) are all spaces
		while(i != s.size() && isspace(s[i]))
		{
			++i;
		}

		// find end of next word
		string_size j = i;
		// invariant: none of the characters in range [original j, current j) is a space
		while(j != s.size() && !isspace(s[j]))
		{
			++j;
		}

		// if we found some nonwhitespace characters
		if(i != j)
		{
			// copy from s starting at i and taking j-i chars
			ret.push_back(s.substr(i,(j-i)));
			i = j;
		}	
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
