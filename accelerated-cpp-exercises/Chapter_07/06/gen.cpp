#include <iostream>
#include <string>
#include <vector>
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

void gen_aux(const grammar &g, std::string word, std::vector<std::string> &ret)
{
	std::vector<std::string> stack;
	bool first_iter = true;
	do
	{
		if(!first_iter)
		{
			word = stack[stack.size()-1];
			stack.pop_back();
		}
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
			const rule &r = c[nrand(c.size())];

			// expand the selected rule non-recursively
			for(rule::const_reverse_iterator i=r.rbegin();i!=r.rend();++i)
			{
				stack.push_back(*i);
			}
		}
		if(first_iter)
		{
			first_iter = false;
		}
	}while(!stack.empty());
}

std::vector<std::string> gen_sentence(const grammar &g)
{
	std::vector<std::string> ret;
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
	std::vector<std::string> sentence = gen_sentence(read_grammar(std::cin));

	// write the first word, if any
	std::vector<std::string>::const_iterator it=sentence.begin();
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
