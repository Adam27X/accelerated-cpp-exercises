#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>
#include <iomanip>

#include "core.hpp"
#include "student_info.hpp"

int main()
{
	std::vector<student_info> did, didnt;
	student_info record;
	std::string::size_type maxlen = 0;

	// read and store the data
	while(record.read(std::cin))
	{
		maxlen = std::max(maxlen,record.name().size());
		if(record.met_all_requirements())
		{
			did.push_back(record);
		}
		else
		{
			didnt.push_back(record);
		}
	}

	std::cout << "Students who met requirements: " << std::endl;
	for(std::vector<student_info>::size_type i=0; i!=did.size(); ++i)
	{	
		std::cout << did[i].name() << std::endl;
	}
	std::cout << "Students who did not meet requirements: " << std::endl;
	for(std::vector<student_info>::size_type i=0; i!=didnt.size(); ++i)
	{	
		std::cout << didnt[i].name() << std::endl;
	}

	return 0;
}
