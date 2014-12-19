#include <iostream>
#include <vector>
#include <fstream>

#include "str.hpp"

int main()
{
	str s = "test.txt";
	const char *cstr = s.c_str();

	std::ifstream ifs(cstr);

	if(!ifs.good())
	{
		std::cout << "File doesn't exist!" << std::endl;
	}

	char *tmp = new char[5];
	s.copy(tmp,5,1);

	for(int i=0; i<4; i++)
	{
		std::cout << tmp[i];
	}
	std::cout << std::endl;
	delete[] tmp;

	return 0;
}
