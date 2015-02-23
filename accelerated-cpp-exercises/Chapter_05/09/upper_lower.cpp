#include <iostream>
#include <vector>
#include <string>
#include <cctype>

int main()
{
	std::string s;
	std::vector<std::string> words;
	while(std::cin >> s)
	{
		words.push_back(s);
	}

	std::vector<std::string> no_upper;
	std::vector<std::string> upper;

	for(std::vector<std::string>::const_iterator i=words.begin();i!=words.end();++i)
	{
		std::string word = *i;
		bool upper_found = false;
		for(unsigned j=0; j<word.size(); j++)
		{
			if(isupper(word[j]))
			{
				upper_found = true;
				break;
			}
		}

		if(upper_found)
		{
			upper.push_back(word);
		}
		else
		{
			no_upper.push_back(word);
		}
	}

	std::cout << "Words with no uppercase letters: " << std::endl;
	for(unsigned j=0; j<no_upper.size(); j++)
	{
		std::cout << no_upper[j] << std::endl;
	}

	std::cout << "Words with at least one uppercase letter: " << std::endl;
	for(unsigned j=0; j<upper.size(); j++)
	{
		std::cout << upper[j] << std::endl;
	}

	return 0;
}
