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

	if(record.valid())
	{
		record.grade();
	}
	else
	{
		std::cout << "Record is not yet valid for grading." << std::endl;
	}

	return 0;
}
