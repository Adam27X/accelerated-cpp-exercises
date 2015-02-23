#include <iostream>
#include <algorithm>

#include "str.hpp"
#include "vec.hpp"

str::size_type width(const vec<str> &v)
{
	str::size_type maxlen = 0;
	for(vec<str>::size_type i=0; i!=v.size(); ++i)
	{
		maxlen = std::max(maxlen,v[i].size());
	}

	return maxlen;
}

vec<str> frame(const vec<str> &v)
{
	vec<str> ret;
	str::size_type maxlen = width(v);
	str border(maxlen + 4,'*');
	
	// write the top border
	ret.push_back(border);

	// write each interior row, bordered by an asterisk and a space
	for(vec<str>::size_type i=0; i!=v.size(); ++i)
	{
		str front("* ");
		str spaces(maxlen - v[i].size(), ' ');
		str back (" *");
	
		ret.push_back(front + v[i] + spaces + back);
	}

	// write the bottom border
	ret.push_back(border);

	return ret;
}

vec<str> vcat(const vec<str> &top, const vec<str> &bottom)
{
	// copy the top picture
	vec<str> ret = top;

	// copy the entire bottom picture
	ret.insert(ret.end(),bottom.begin(),bottom.end());

	return ret;
}

vec<str> hcat(const vec<str> &left, const vec<str> &right)
{
	vec<str> ret;

	// add 1 to leave a space between pictures
	str::size_type width1 = width(left) + 1;

	// indices to look at elements from left and right respectively
	vec<str>::size_type i=0, j=0;
	
	// continue until we've seen all rows from both pictures
	while(i != left.size() || j != right.size())
	{
		// construct new string to hold characters from both pictures
		str s;
	
		// copy a row from the left-hand side, if there is one
		if(i != left.size())
		{
			s = left[i++];
		}

		// pad to full width
		s += str(width1 - s.size(), ' ');

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
	vec<str> test;
	str s;

	while(getline(std::cin,s))
	{
		test.push_back(s);
	}

	vec<str> result = vcat(hcat(test,frame(test)),hcat(frame(test),test));

	for(vec<str>::const_iterator i=result.begin(),e=result.end();i!=e;++i)
	{
		std::cout << *i << std::endl;
	}

	return 0;
}
