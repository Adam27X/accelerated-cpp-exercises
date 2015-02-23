#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

/*
Example input:

The quick brown fox
jumped over the fence

Output:

The quick       *brown* fox
jumped over the *fence*
The quick brown *fox*
                *jumped* over the fence
         jumped *over* the fence
	    The *quick* brown fox	
    jumped over *the* fence
                *The* quick brown fox

Task at hand:

Note the starred word on each line. Each word in the input appears as a starred word exactly once. 
These words appear in lexicographical order. Each line corresponds to one of the lines of input.
Essentially, the task is to order the words of all lines of input and then print these words, along with their respective line, 
in order with the proper formatting to make the first character of the bolded (key) words line up.

Reference: http://en.wikipedia.org/wiki/Key_Word_in_Context
*/

std::vector<std::string> split(const std::string &s)
{
        std::vector<std::string> ret;
        typedef std::string::size_type string_size;
        string_size i=0;

        // invariant: we have processed characters [original value of i,i)
        while(i != s.size())
        {
                // ignore leading blanks
                // invariant: characters in range [original i,current i) are all spaces
                while(i != s.size() && isspace(s[i]))
                {
                        ++i;
                }

                // find end of next word
                string_size j = i;
                // invariant: none of the characters in range [original j, current j) is a space
                while(j != s.size() && !isspace(s[j]))
                {
                        ++j;
                }

                // if we found some nonwhitespace characters
                if(i != j)
                {
                        // copy from s starting at i and taking j-i chars
                        ret.push_back(s.substr(i,j-i));
                        i = j;
                }
        }

        return ret;
}

struct rotated_line
{
	std::string line;
	std::string::size_type delimiter;
};

bool compare_rotated_lines(const rotated_line &x, const rotated_line &y)
{
	return x.line < y.line;
}

int main()
{
	std::string line;
	std::vector<rotated_line> rotations; //Store all rotations of the line as a vector of strings as we will need to sort this data
	std::string::size_type max_width = 0;
	while(std::getline(std::cin,line))
	{
		rotated_line temp;
		temp.line = line;
		if(line.size() > max_width)
		{
			max_width = line.size();
		}
		temp.delimiter = 0;
		rotations.push_back(temp);
		std::vector<std::string> words = split(line);
	
		//Repeatedly tack the front of the list to the end of the list until we get back the original list. For a list of length n, this means n-1 tackings.	
		int tackings = 1;
		while(tackings < words.size())
		{
			std::string front = words[0];
			words.erase(words.begin()); //Erase front element
			words.push_back(front); //Append to back

			rotated_line temp;
			temp.line = "";
			temp.delimiter = 0;
			int j=0;
			for(std::vector<std::string>::const_iterator i=words.begin(),e=words.end();i!=e;++i)
			{
				if((i+1) == words.end())
				{
					temp.line += (*i);
				}
				else
				{
					temp.line += (*i) + " ";
				}

				if(j < words.size()-tackings)
				{
					temp.delimiter += (*i).size() + 1;
				}
				j++;
			}
			
			rotations.push_back(temp);

			tackings++;
		}

		
	}

	//Sort the rotations
	std::sort(rotations.begin(),rotations.end(),compare_rotated_lines);

	//Write out the result
	for(unsigned i=0; i<rotations.size(); i++)
	{
		std::string line = rotations[i].line;
		std::string::size_type delimiter = rotations[i].delimiter;
		std::string left_side(line.begin()+delimiter,line.end());
		std::string right_side(line.begin(),line.begin()+delimiter);
		if(delimiter == 0)
		{
			left_side = "";
			right_side = line;
		}
		std::cout << std::setw(max_width) << left_side << "\t" << right_side << std::endl;
	}	

	return 0;
}
