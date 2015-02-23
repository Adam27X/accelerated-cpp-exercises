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
	std::vector<student_info> students;
	student_info record;
	std::string::size_type maxlen = 0;

	// read and store the data
	while(record.read(std::cin))
	{
		maxlen = std::max(maxlen,record.name().size());
		students.push_back(record);
	}

	std::cout << "Testing validity: ";
	students[0].valid() ? std::cout << "Pass." : std::cout << "Fail.";
	std::cout << std::endl;

	student_info record2;
	std::cout << "Testing invalidity: ";
	!record2.valid() ? std::cout << "Pass." : std::cout << "Fail.";
	std::cout << std::endl;

	return 0;
}
