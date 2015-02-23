//The problem statement doesn't specify if the number of unique words or simply the total number of words are desired. We assume the former.
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

std::istream& read_words(std::istream &cin, std::vector<std::string> &words)
{
	if(cin)
	{
		//get rid of previous contents
		words.clear();

		//read in words
		std::string s;
		while(cin >> s)
		{
			words.push_back(s);
		}

		// clear the stream so that input will work again
		cin.clear();
	}

	return cin;
}

int main()
{
	std::vector<std::string> words;
	read_words(std::cin,words);

	std::sort(words.begin(),words.end());

	if(words.size() < 2)
	{
		std::cout << "Number of words: " << words.size() << std::endl;
		if(words.size() == 1)
		{
			std::cout << "Number of occurrences for each word: " << std::endl;
			std::cout << words[0] << ": 1" << std::endl;
		}

		return 0;
	}

	int num_words = 1;
	int current_count = 1;
	std::string current = words[0];
	std::cout << "Number of occurrences for each word: " << std::endl;
	for(unsigned i=1; i<words.size(); i++)
	{
		if(words[i] == current)
		{
			current_count++;
		}
		else
		{
			std::cout << current << ": " << current_count << std::endl;
			current = words[i];
			current_count = 1;
			num_words++; 
		}
	}

	//handle the last word
	std::cout << current << ": " << current_count << std::endl;
	std::cout << "Number of unique words: " << num_words << std::endl;
	
	return 0;
}
