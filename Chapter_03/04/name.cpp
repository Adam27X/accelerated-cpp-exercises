#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int main()
{
	std::cout << "Please enter a list of words: ";
	std::string x;
	typedef std::string::size_type sz;
	std::vector<sz> data;

	while(std::cin >> x)
	{
		data.push_back(x.size());
	}

	if(data.size() == 0)
	{
		std::cout << "Error, invalid data." << std::endl;
		return 1;
	}
	std::sort(data.begin(),data.end()); //Can do this in linear time with a scan instead
	sz shortest = data[0];
	sz longest = data[data.size()-1];

	std::cout << "Size of the shortest string: " << shortest << std::endl;
	std::cout << "Size of the longest string: " << longest << std::endl;

	return 0;
}
