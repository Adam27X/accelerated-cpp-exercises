#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <stdexcept>

typedef std::list<std::string> rule;
typedef std::list<rule> rule_collection;
typedef std::map<std::string, rule_collection> grammar;

bool space(char c)
{
        return isspace(c);
}

bool not_space(char c)
{
        return !isspace(c);
}

std::list<std::string> split(const std::string &s)
{
        typedef std::string::const_iterator iter;
        std::list<std::string> ret;

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

bool bracketed(const std::string &s)
{
	return s.size() > 1 && s[0] == '<' && s[s.size()-1] == '>';
}

// return a random integer in the range [0,n_
int nrand(int n)
{
	if(n <= 0 || n > RAND_MAX)
	{
		throw std::domain_error("Argument to nrand is out of range");
	}

	const int bucket_size = RAND_MAX/n;
	int r;

	do
	{
		r = rand() / bucket_size;
	} while(r >= n);

	return r;
}

void gen_aux(const grammar &g, const std::string &word, std::list<std::string> &ret)
{
	if(!bracketed(word))
	{
		ret.push_back(word);
	}
	else
	{
		// locate the rule that corresponds to word
		grammar::const_iterator it = g.find(word);
		if(it == g.end())
		{
			throw std::logic_error("empty rule");
		}

		// fetch the set of possible rules
		const rule_collection &c = it->second;

		// from which we select one at random
		int choice = nrand(c.size());
		rule_collection::const_iterator rit = c.begin();
		while(choice)
		{
			++rit;
			--choice;;
		}
		const rule &r = *rit;
		//const rule &r = c[nrand(c.size())];

		// recursively expand the selected rule
		for(rule::const_iterator i=r.begin();i!=r.end();++i)
		{
			gen_aux(g,*i,ret);
		}
	}
}

std::list<std::string> gen_sentence(const grammar &g)
{
	std::list<std::string> ret;
	gen_aux(g,"<sentence>",ret);
	return ret;
}

grammar read_grammar(std::istream &in)
{
	grammar ret;
	std::string line;

	// read the input
	while(std::getline(in,line))
	{
		// split the input into words
		std::list<std::string> entry = split(line);

		if(!entry.empty())
		{
			// use the category to store the associated rule
			std::string index = *(entry.begin());
			ret[index].push_back(rule(++entry.begin(),entry.end()));
		}
	}

	return ret;
}

int main()
{
	// generate the sentence
	std::list<std::string> sentence = gen_sentence(read_grammar(std::cin));

	// write the first word, if any
	std::list<std::string>::const_iterator it=sentence.begin();
	if(!sentence.empty())
	{
		std::cout << *it;
		++it;
	}

	// write the rest of the words, each preceded by a space
	while(it != sentence.end())
	{
		std::cout << " " << *it;
		++it;
	}
	std::cout << std::endl;

	return 0;
}
