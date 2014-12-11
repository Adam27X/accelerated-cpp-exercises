#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <numeric>

#include "grade.h"
#include "student_info.h"
#include "median.h"

double average(const std::vector<double> &v)
{
	return std::accumulate(v.begin(),v.end(),0.0) / v.size();
}

double average_grade(const student_info &s)
{
	return grade(s.midterm_exam,s.final_exam,average(s.homework));
}

/*double average_analysis(const std::vector<student_info> &students)
{
	std::vector<double> grades;
	std::transform(students.begin(),students.end(),std::back_inserter(grades),average_grade);
	
	return median(grades);
}*/

double optimistic_median(const student_info &s)
{
	std::vector<double> nonzero;
	std::remove_copy(s.homework.begin(),s.homework.end(),std::back_inserter(nonzero),0);

	if(nonzero.empty())
	{
		return grade(s.midterm_exam,s.final_exam,0);
	}
	else
	{
		return grade(s.midterm_exam,s.final_exam,median(nonzero));
	}
}

/*double optimistic_median_analysis(const std::vector<student_info> &students)
{
	std::vector<double> grades;
	std::transform(students.begin(),students.end(),std::back_inserter(grades),optimistic_median);
	
	return median(grades);
}*/

double grade_aux(const student_info &s)
{
	try
	{
		return grade(s);
	}
	catch(std::domain_error)
	{
		return grade(s.midterm_exam,s.final_exam,0);
	}
}

double analysis(const std::vector<student_info> &students, double grader(const student_info &s))
{
	std::vector<double> grades;
	std::transform(students.begin(),students.end(),std::back_inserter(grades),grader);

	return median(grades);
}

void write_analysis(std::ostream &out, const std::string &name, const std::vector<student_info> &did, const std::vector<student_info> &didnt, double grader(const student_info &s))
{
	out << name << "; median(did) = " << analysis(did,grader) << ", median(didn't) = " << analysis(didnt,grader) << std::endl;
}

std::vector<student_info> extract_no_hw(std::vector<student_info> &students)
{
	std::vector<student_info>::iterator iter = std::stable_partition(students.begin(),students.end(),did_all_hw);
	std::vector<student_info> didnt(iter,students.end());
	students.erase(iter,students.end());

	return didnt;
}

int main()
{
	std::vector<student_info> did,didnt;
	student_info student;

	while(read(std::cin,student))
	{
		did.push_back(student);
	}

	didnt = extract_no_hw(did);

	std::cout << "Students that did all hw: " << std::endl;
	for(unsigned i=0; i<did.size(); i++)
	{
		std::cout << did[i].name << std::endl;
	}

	std::cout << "Students that did not do all hw: " << std::endl;
	for(unsigned i=0; i<didnt.size(); i++)
	{
		std::cout << didnt[i].name << std::endl;
	}

	return 0;
}
