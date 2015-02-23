#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char **argv)
{
	int fail_count = 0;
	// for each file in the input list
	for(int i=1; i<argc; i++)
	{
		std::ifstream in(argv[i]);

		// if it exists, write its contents, otherwise generate an error message
		if(in)
		{
			std::string s;
			while(std::getline(in,s))
			{
				std::cout << s << std::endl;
			}
		}
		else
		{
			std::cerr << "Cannot open file " << argv[i] << std::endl;
			++fail_count;
		}
	}

	return fail_count;
}
