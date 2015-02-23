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

	// read and store the data
	while(record.read(std::cin))
	{
		maxlen = std::max(maxlen,record.name().size());
		students.push_back(record);
	}

	// alphabetize the student records
	std::sort(students.begin(),students.end(),compare);

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

	students[0].print_statistics();

	return 0;
}
