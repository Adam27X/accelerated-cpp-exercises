#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <stdexcept>

typedef std::vector<std::string> rule;
typedef std::vector<rule> rule_collection;
typedef std::map<std::string, rule_collection> grammar;

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

template <class OutputIterator>
void gen_aux(const grammar &g, const std::string &word, OutputIterator ret)
{
	if(!bracketed(word))
	{
		//ret.push_back(word);
		*ret++ = word;
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
		const rule &r = c[nrand(c.size())];

		// recursively expand the selected rule
		for(rule::const_iterator i=r.begin();i!=r.end();++i)
		{
			gen_aux(g,*i,ret);
		}
	}
}

template <class OutputIterator>
void gen_sentence(const grammar &g, OutputIterator ret)
{
	gen_aux(g,"<sentence>",ret);
}

grammar read_grammar(std::istream &in)
{
	grammar ret;
	std::string line;

	// read the input
	while(std::getline(in,line))
	{
		// split the input into words
		std::vector<std::string> entry = split(line);

		if(!entry.empty())
		{
			// use the category to store the associated rule
			ret[entry[0]].push_back(rule(entry.begin()+1,entry.end()));
		}
	}

	return ret;
}

int main()
{
	// generate the sentence
	grammar g  = read_grammar(std::cin);
	std::cout << "Using std::cout directly: " << std::endl;
	gen_sentence(g, std::ostream_iterator<std::string>(std::cout, " "));
	std::cout << std::endl;

	std::cout << std::endl << "Using list<string>: " << std::endl;
	std::list<std::string> l;
	gen_sentence(g,std::back_inserter(l));
	for(std::list<std::string>::const_iterator i=l.begin(); i!=l.end(); ++i)
	{
		std::cout << *i << " ";
	}
	std::cout << std::endl;

	/*std::cout << std::endl << "Using map<string, vector<int> >: " << std::endl;
	std::map<std::string, std::vector<int> > m;
	gen_sentence(g,std::inserter(m,m.begin()));
	for(std::map<std::string, std::vector<int> >::const_iterator i=m.begin();i!=m.end();++i)
	{
		std::cout << i->first << " ";
	}
	std::cout << std::endl;*/

	return 0;
}
