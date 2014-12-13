#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

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

std::map<std::string, std::vector<int> > xref(std::istream &in, std::vector<std::string> find_words(const std::string &s) = split)
{
	std::string line;
	int line_number = 0;
	std::map<std::string, std::vector<int> > ret;

	// read the next line
	while(std::getline(in,line))
	{
		++line_number;

		// break the input line into words
		std::vector<std::string> words = find_words(line);

		// remember that each word occurs on the current line
		for(std::vector<std::string>::const_iterator it=words.begin();it!=words.end();++it)
		{
			ret[*it].push_back(line_number);
		}
	}

	return ret;
}

int main()
{
	// call xref using split by default
	std::map<std::string, std::vector<int> > ret = xref(std::cin);

	// write the results
	for(std::map<std::string, std::vector<int> >::const_iterator it=ret.begin();it!=ret.end();++it)
	{
		// write the word
		std::cout << it->first << " occurs on line(s): ";

		// followed by one or more line numbers
		std::vector<int>::const_iterator line_it = it->second.begin();
		std::cout << *line_it;

		++line_it;
		// write the rest of the line numbers, if any
		while(line_it != it->second.end())
		{
			std::cout << "," << *line_it;
			++line_it;
		}

		// write a new line to separate each word from the list
		std::cout << std::endl;
	}

	return 0;
}
