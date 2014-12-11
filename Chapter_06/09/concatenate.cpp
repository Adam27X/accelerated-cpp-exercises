#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

int main()
{
	std::vector<std::string> text;
	std::string s;

	while(std::cin >> s)
	{
		text.push_back(s);
	}

	std::string concat = std::accumulate(text.begin(),text.end(),std::string(""));

	std::cout << "Concatenated string: " << concat << std::endl;

	return 0;
}
