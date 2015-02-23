#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::string::size_type width(const std::vector<std::string> &v)
{
	std::string::size_type maxlen = 0;
	for(std::vector<std::string>::size_type i=0; i!=v.size(); ++i)
	{
		maxlen = std::max(maxlen,v[i].size());
	}

	return maxlen;
}

std::vector<std::string> frame(const std::vector<std::string> &v)
{
	std::vector<std::string> ret;
	std::string::size_type maxlen = width(v);
	std::string border(maxlen + 4,'*');
	
	// write the top border
	ret.push_back(border);

	// write each interior row, bordered by an asterisk and a space
	for(std::vector<std::string>::size_type i=0; i!=v.size(); ++i)
	{
		ret.push_back("* " + v[i] + std::string(maxlen - v[i].size(),' ') + " *");
	}

	// write the bottom border
	ret.push_back(border);

	return ret;
}

std::vector<std::string> vcat(const std::vector<std::string> &top, const std::vector<std::string> &bottom)
{
	// copy the top picture
	std::vector<std::string> ret = top;

	// copy the entire bottom picture
	ret.insert(ret.end(),bottom.begin(),bottom.end());

	return ret;
}

std::vector<std::string> hcat(const std::vector<std::string> &left, const std::vector<std::string> &right)
{
	std::vector<std::string> ret;

	// add 1 to leave a space between pictures
	std::string::size_type width1 = width(left) + 1;

	// indices to look at elements from left and right respectively
	std::vector<std::string>::size_type i=0, j=0;
	
	// construct new string outside of the while loop. Causes an error because of the s += stmt below that depends on s.size()
	std::string s;
	// continue until we've seen all rows from both pictures
	while(i != left.size() || j != right.size())
	{
		s = ""; //This fixes the error. Put here just so we have a working program.
	
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
	std::vector<std::string> test;
	std::string s;

	while(std::getline(std::cin,s))
	{
		test.push_back(s);
	}

	std::vector<std::string> result = hcat(test,frame(test));

	for(std::vector<std::string>::const_iterator i=result.begin(),e=result.end();i!=e;++i)
	{
		std::cout << *i << std::endl;
	}

	return 0;
}
