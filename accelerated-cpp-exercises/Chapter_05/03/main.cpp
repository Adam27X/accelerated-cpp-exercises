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

//typedef std::vector<student_info> student_class;
typedef std::list<student_info> student_class;

// predicate to determine whether a student failed
bool fgrade(const student_info &s)
{
	return grade(s) < 60;
}

student_class extract_fails(student_class &students)
{
	student_class fail;
	student_class::iterator iter = students.begin();

	while(iter != students.end())
	{
		if(fgrade(*iter))
		{
			fail.push_back(*iter);
			iter = students.erase(iter);
		}
		else
		{
			++iter;
		}
	}	

	return fail;
}

int main()
{
	student_class students;
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
	//std::sort(students.begin(),students.end(),compare);

	//transfer to a list
	student_class students_passed(students.begin(),students.end());
	student_class students_failed = extract_fails(students_passed);

	std::cout << "Passing students: " << std::endl;
	typedef student_class::const_iterator vec_citer;
	for(vec_citer i=students_passed.begin(); i!=students_passed.end(); ++i)
	{
		std::cout << (*i).name << std::endl;
	}
	std::cout << "Failing students: " << std::endl;
	for(vec_citer i=students_failed.begin(); i!=students_failed.end(); ++i)
	{
		std::cout << (*i).name << std::endl;
	}

	return 0;
}
