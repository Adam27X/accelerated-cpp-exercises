#include <iostream>
#include <vector>
#include <string>

#include "picture.hpp"
#include "student_info.hpp"

picture histogram(const std::vector<student_info> &students)
{
	picture names;
	picture grades;
	
	// for each student
	for(std::vector<student_info>::const_iterator it=students.begin(); it!=students.end(); ++it)
	{
		// create vertically concatenated pictures of the names and grades
		names = vcat(names, std::vector<std::string>(1,it->name()));
		grades = vcat(grades, std::vector<std::string>(1," " + std::string(it->grade() /5, '=')));
	}

	// horinzontally concatenate the name and grade pictures
	return hcat(names,grades);
}

int main()
{
	std::vector<student_info> students;
	student_info s;
	
	// read the names and grades
	while(s.read(std::cin))
	{
		students.push_back(s);
	}

	// put the students in alphabetical order
	std::sort(students.begin(),students.end(),student_info::compare);

	// write the names and histograms
	std::cout << frame(histogram(students));
	std::cout << std::endl;

	return 0;
}
