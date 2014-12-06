#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int main()
{
	std::cout << "Please enter a list of words: ";
	std::string x;
	std::vector<std::string> data;

	while(std::cin >> x)
	{
		data.push_back(x);
	}

	//A map seems better for this sort of task, but the book hasn't covered maps yet
	//Strategy: Sort the strings and keep a running sum
	std::sort(data.begin(),data.end());

	if(data.size() == 0)
	{
		std::cout << "Error, invalid data." << std::endl;
		return 1;
	}

	std::string current = data[0];
	unsigned count = 1;
	for(unsigned i=1; i<data.size(); i++)
	{
		if(current == data[i])
		{
			count++;
		}
		else
		{
			std::cout << "Number of occurrences for \"" << current << ":\"" << count << std::endl;
			current = data[i];
			count = 1;
		}
	}
	//Output the last word of the list
	std::cout << "Number of occurrences for \"" << current << ":\"" << count << std::endl;

	return 0;
}
