//A cool way to test this program is to use /usr/share/dict/american-english as input
#include <iostream>
#include <vector>
#include <cctype>
#include <string>

int main()
{
	std::string s;
	std::vector<std::string> fixed_height;

	while(std::cin >> s)
	{
		for(unsigned i=0; i<s.size(); i++)
		{
			if(!isalpha(s[i]))
			{
				break;
			}
			if(s[i] == 'b' || s[i] == 'd' || s[i] == 'f' || s[i] == 'h' || s[i] == 'k' || s[i] == 'l' 
			|| s[i] == 't' || s[i] == 'g' || s[i] == 'j' || s[i] == 'p' || s[i] == 'q' || s[i] == 'y')
			{
				break;
			}
			if(i == s.size()-1)
			{
				fixed_height.push_back(s);
			}
		}
	}

	std::string::size_type maxlen = 0;
	std::string longest = "";
	for(unsigned i=0; i<fixed_height.size(); i++)
	{
		if(fixed_height[i].size() > maxlen)
		{
			maxlen = fixed_height[i].size();
			longest = fixed_height[i];
		}
	}

	std::cout << "Number of words containing no ascenders nor descenders: " << fixed_height.size() << std::endl;
	std::cout << "Longest such word: " << longest << " (length: " << maxlen << ")" << std::endl;

	return 0;
}
