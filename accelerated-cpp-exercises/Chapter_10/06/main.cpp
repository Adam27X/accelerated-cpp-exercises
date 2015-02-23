#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>
#include <cctype>

#include "string_list.hpp"

bool space(char c)
{
        return isspace(c);
}

bool not_space(char c)
{
        return !isspace(c);
}

void split(const std::string &s, string_list &l)
{
	typedef std::string::const_iterator iter;

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
			l.push_back(std::string(i,j)); 
		}

		i = j;
	}
}

int main()
{
	string_list l;
	std::string s;
	while(std::getline(std::cin,s))
	{
		split(s,l);
	}
	l.print_forward();
	
	return 0;
}
