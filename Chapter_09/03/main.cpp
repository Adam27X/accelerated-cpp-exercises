#include <iostream>
#include <algorithm>
#include <iomanip>
#include <stdexcept>

#include "student_info.h"

int main()
{
	std::vector<student_info> students;
	student_info record;
	std::string::size_type maxlen = 0;

	try
	{
		record.grade(); // Throws an exception because we haven't read any data yet
	}
	catch(std::domain_error e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
