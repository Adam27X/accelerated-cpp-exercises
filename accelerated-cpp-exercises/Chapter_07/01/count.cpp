#include <iostream>
#include <vector>
#include <map>
#include <string>

int main()
{
	std::string s;
	std::map<std::string,int> counters; // store each word and an associated counter

	// read the input, keeping track of each word and how often we see it
	while(std::cin >> s)
	{
		++counters[s];
	}

	// Now arrange the pairs by the count rather than the word
	std::map<int,std::vector<std::string> > count_to_words;
	for(std::map<std::string,int>::const_iterator it=counters.begin(); it!=counters.end(); ++it)
	{
		count_to_words[it->second].push_back(it->first);
	}

	for(std::map<int,std::vector<std::string> >::const_iterator it=count_to_words.begin(); it!=count_to_words.end(); ++it)
	{
		std::vector<std::string> words = it->second;
		std::cout << "Number of words occurring " << it->first << " time(s): ";
		std::cout << words[0]; //guaranteed to have at least one entry, else it wouldn't be an entry in the map
		for(std::vector<std::string>::const_iterator wit=words.begin()+1;wit!=words.end();++wit)
		{
			std::cout << ", " << *wit;
		}
		std::cout << std::endl;
	}

	return 0;
}
