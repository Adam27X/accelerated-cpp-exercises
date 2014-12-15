#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>

bool space(char c)
{
        return isspace(c);
}

bool not_space(char c)
{
        return !isspace(c);
}

template <class OutputIterator>
void split(const std::string &s, OutputIterator os)
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
			*os++ = std::string(i,j); 
		}

		i = j;
	}
}

int main()
{
	std::string s;
	while(std::getline(std::cin,s))
	{
		split(s,std::ostream_iterator<std::string>(std::cout,"\n"));
	}

	return 0;
}
