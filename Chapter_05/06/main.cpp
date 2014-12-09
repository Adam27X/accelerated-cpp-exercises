#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <list>

#include "grade.h"
#include "student_info.h"

// predicate to determine whether a student failed
bool fgrade(const student_info &s)
{
	return grade(s) < 60;
}

std::vector<student_info> extract_fails(std::vector<student_info> &students)
{
	std::vector<student_info> fail;
	std::vector<student_info>::iterator iter = students.begin();

	int i=0;
	int passed = 0;
	while(i != students.size())
	{
		if(fgrade(students[i]))
		{
			fail.push_back(students[i]);
		}
		else
		{
			students.insert(students.begin(),students[i++]);
			passed++;
		}
		i++;
	}
	students.resize(passed);	

	return fail;
}

int main()
{
	std::vector<student_info> students;
	student_info record;
	std::string::size_type maxlen = 0; //the length of the longest name
	
	//read and store all the students' data
	//Invariant: students contains all the student records read so far
	//	     maxlen contains the length of the longest name in students
	while(read(std::cin,record))
	{
		// find length of longest name
		maxlen = std::max(maxlen,record.name.size());
		students.push_back(record);
	}	

	//alphabetize the student records
	std::sort(students.begin(),students.end(),compare);

	//transfer to a vector
	std::vector<student_info> students_passed(students.begin(),students.end());
	std::vector<student_info> students_failed = extract_fails(students_passed);

	std::cout << "Passing students: " << std::endl;
	typedef std::vector<student_info>::const_iterator vector_citer;
	for(vector_citer i=students_passed.begin(); i!=students_passed.end(); ++i)
	{
		std::cout << (*i).name << std::endl;
	}
	std::cout << "Failing students: " << std::endl;
	for(vector_citer i=students_failed.begin(); i!=students_failed.end(); ++i)
	{
		std::cout << (*i).name << std::endl;
	}

	return 0;
}
