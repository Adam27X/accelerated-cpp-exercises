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

int main()
{
	std::vector<student_info> did, didnt;
	student_info student;

	while(read(std::cin,student))
	{
		if(did_all_hw(student))
		{
			did.push_back(student);
		}
		else
		{
			didnt.push_back(student);
		}
	}

	// check that both groups contain data
	if(did.empty())
	{
		std::cout << "No student did all of the homework!" << std::endl;
		return 1;
	}
	else if(didnt.empty())
	{
		std::cout << "Every student did all of the homework!" << std::endl;
		return 1;
	}

	// do the analyses
	write_analysis(std::cout, "median", did, didnt,grade_aux);
	write_analysis(std::cout, "average", did, didnt,average_grade);
	write_analysis(std::cout, "median of homework turned in", did, didnt,optimistic_median);

	return 0;
}
