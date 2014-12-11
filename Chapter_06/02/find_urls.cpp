#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cctype>

bool not_url_char(char c)
{
	// characters, in addition to alphanumerics, that can appear in a url
	static const std::string url_ch = "~;/?:@=&$-_.+!*'(),";

	// see whether c can appear in a url and returm the negative
	return !(isalnum(c) || std::find(url_ch.begin(),url_ch.end(),c) != url_ch.end());
}

std::string::const_iterator url_beg(std::string::const_iterator b, std::string::const_iterator e)
{
	static const std::string sep = "://";

	typedef std::string::const_iterator iter;

	// i marks where the separator was found
	iter i=b;

	while((i = std::search(i,e,sep.begin(),sep.end())) != e)
	{
		// make sure the iterator isn't at the beginning or end of the line
		if(i != b && i + sep.size() != e)
		{
			// beg marks the beginning of the protocol-name
			iter beg = i;
			while(beg != b && isalpha(beg[-1]))
			{
				--beg;
			}

			// is there at least one appropriate character before and after the separator?
			if(beg != i && !not_url_char(i[sep.size()]))
			{
				return beg;
			}
		}
	
		// the separator we found wasn't part of a url; advance i past this separator
		i += sep.size();
	}
	
	return e;
}

std::string::const_iterator url_end(std::string::const_iterator b, std::string::const_iterator e)
{
	return std::find_if(b,e,not_url_char);
}

std::vector<std::string> find_urls(const std::string &s)
{
	std::vector<std::string> ret;
	typedef std::string::const_iterator iter;
	iter b = s.begin(), e = s.end();

	// look through the entire input
	while(b!=e)
	{
		// look for one or more letters followed by ://
		b = url_beg(b,e);

		// if we found it
		if(b!=e)
		{
			// get the rest of the url
			iter after = url_end(b,e);

			// remember the url
			ret.push_back(std::string(b,after));

			// advance b and check for more urls on this line
			b = after;
		}
	}

	return ret;
}

int main()
{
	std::string s;
	std::getline(std::cin,s);
	std::vector<std::string> urls = find_urls(s);	

	std::cout << "urls: " << std::endl;
	for(unsigned i=0; i<urls.size(); i++)
	{
		std::cout << urls[i] << std::endl;
	}	

	return 0;
}
