#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <map>

#include "grade.h"
#include "student_info.h"

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

	//write the names and grades
	std::map<char,std::vector<student_info> > letter_to_students;
	for(std::vector<student_info>::size_type i=0; i!=students.size(); i++)
	{
		//compute and write the grade
		try
		{
			char final_grade = grade_letter(students[i]);
			letter_to_students[final_grade].push_back(students[i]);
		}
		catch(std::domain_error e)
		{
			std::cout << e.what();
		}
	}

	for(std::map<char,std::vector<student_info> >::const_iterator it=letter_to_students.begin();it!=letter_to_students.end();++it)
	{
		const std::vector<student_info> assoc_students = it->second;
		std::cout << "Students with grade " << it->first << " (" << assoc_students.size() << "): ";
		std::cout << assoc_students[0].name;
		for(std::vector<student_info>::const_iterator ait=assoc_students.begin()+1;ait!=assoc_students.end();++ait)
		{
			std::cout << ", " << ait->name;
		}
		std::cout << std::endl;
	}

	return 0;
}
