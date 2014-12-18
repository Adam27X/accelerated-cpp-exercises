#include <iostream>
#include <algorithm>
#include <iomanip>
#include <stdexcept>
#include <string>

#include "student_info.h"

std::string letter_grade(double grade)
{
	// range posts for numeric grades
	static const double numbers[] = {
		97, 94, 90, 87, 84, 80, 77, 74, 70, 60, 0
	};
	
	// names for the letter grades
	static const char* const letters[] = {
		"A+", "A", "A-", "B+", "B", "B-", "C+", "C", "C-", "D", "F"
	};

	// compute the number of grades given the size of the array
	// and the size of a single element
	static const size_t ngrades = sizeof(numbers)/sizeof(*numbers);

	// given a numeric grade, find and return the associated letter grade
	for(size_t i=0; i<ngrades; ++i)
	{
		if(grade >= numbers[i])
		{
			return letters[i];
		}
	}

	return "?\?\?";
}

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
			std::string letter = letter_grade(final_grade);
			std::cout << letter << std::endl;
		}
		catch(std::domain_error e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	return 0;
}
