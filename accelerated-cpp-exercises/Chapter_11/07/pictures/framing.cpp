#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "vec.hpp"

std::string::size_type width(const vec<std::string> &v)
{
	std::string::size_type maxlen = 0;
	for(vec<std::string>::size_type i=0; i!=v.size(); ++i)
	{
		maxlen = std::max(maxlen,v[i].size());
	}

	return maxlen;
}

vec<std::string> frame(const vec<std::string> &v)
{
	vec<std::string> ret;
	std::string::size_type maxlen = width(v);
	std::string border(maxlen + 4,'*');
	
	// write the top border
	ret.push_back(border);

	// write each interior row, bordered by an asterisk and a space
	for(vec<std::string>::size_type i=0; i!=v.size(); ++i)
	{
		ret.push_back("* " + v[i] + std::string(maxlen - v[i].size(),' ') + " *");
	}

	// write the bottom border
	ret.push_back(border);

	return ret;
}

vec<std::string> vcat(const vec<std::string> &top, const vec<std::string> &bottom)
{
	// copy the top picture
	vec<std::string> ret = top;

	// copy the entire bottom picture
	ret.insert(ret.end(),bottom.begin(),bottom.end());

	return ret;
}

vec<std::string> hcat(const vec<std::string> &left, const vec<std::string> &right)
{
	vec<std::string> ret;

	// add 1 to leave a space between pictures
	std::string::size_type width1 = width(left) + 1;

	// indices to look at elements from left and right respectively
	vec<std::string>::size_type i=0, j=0;
	
	// continue until we've seen all rows from both pictures
	while(i != left.size() || j != right.size())
	{
		// construct new string to hold characters from both pictures
		std::string s;
	
		// copy a row from the left-hand side, if there is one
		if(i != left.size())
		{
			s = left[i++];
		}

		// pad to full width
		s += std::string(width1 - s.size(), ' ');

		// copy a row from the right-hand side, if there is one
		if(j != right.size())
		{
			s += right[j++];
		}

		// add s to the picture we're making
		ret.push_back(s);
	}

	return ret;

}

int main()
{
	vec<std::string> test;
	std::string s;

	while(std::getline(std::cin,s))
	{
		test.push_back(s);
	}

	vec<std::string> result = vcat(hcat(test,frame(test)),hcat(frame(test),test));

	for(vec<std::string>::const_iterator i=result.begin(),e=result.end();i!=e;++i)
	{
		std::cout << *i << std::endl;
	}

	return 0;
}
