//A very cool way to test this program is to use /usr/share/dict/american-english as input
#include <iostream>
#include <string>
#include <vector>
#include <cctype>

int main()
{
	std::string s;
	std::vector<std::string> palindromes;

	while(std::cin >> s)
	{
		//Test to see if the string is a palindrome
		for(unsigned i=0; i<s.size(); i++)
		{
			//Technically, palindromes only have letters
			if(!isalpha(s[i]))
			{
				break;
			}

			int j = s.size()-i-1;
			if(i > j)
			{
				//Made it so far without breaking so we have a palindrome
				palindromes.push_back(s);
				break;
			}
			else
			{
				if(s[i] != s[j])
				{
					break;
				}
			}
		}
	}

	std::string::size_type maxlen = 0;
	std::string longest = "";
	std::cout << "List of palindromes: " << std::endl;
	for(unsigned i=0; i<palindromes.size(); i++)
	{
		if(palindromes[i].size() > maxlen)
		{
			maxlen = palindromes[i].size();
			longest = palindromes[i];
		}
		std::cout << palindromes[i] << std::endl;
	}	

	std::cout << "Longest palindrome: " << longest << " (legnth: " << maxlen << ")" << std::endl;

	return 0;
}
