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

	// alphabetize the student records
	sort(students.begin(),students.end(),student_info::compare);

	// write the names and grades
	for(std::vector<student_info>::size_type i=0; i!=students.size(); ++i)
	{
		std::cout << students[i].name() << std::string(maxlen + 1 - students[i].name().size(), ' ');
		try
		{
			double final_grade = students[i].grade();
			std::streamsize prec = std::cout.precision();
			std::cout << std::setprecision(3) << final_grade << std::setprecision(prec) << std::endl;
		}
		catch(std::domain_error e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	return 0;
}
