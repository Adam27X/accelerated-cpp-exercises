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
#include "median.hpp"

double average(const std::vector<double> &v)
{
	return std::accumulate(v.begin(),v.end(),0.0) / v.size();
}

double average_grade(const student_info &s)
{
	return grade(s.midterm_exam,s.final_exam,average(s.homework));
}

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
		return grade(s.midterm_exam,s.final_exam,median<double>(nonzero.begin(),nonzero.end()));
	}
}

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

template <class Function>
double analysis(const std::vector<student_info> &students, Function grading_func)
{
	std::vector<double> grades;
	std::transform(students.begin(),students.end(),std::back_inserter(grades),grading_func);

	const int num_grades = 5;	
	double *grades_arr = new double[num_grades]; //Use an array instead of a vector to test the median function
	std::copy(grades.begin(),grades.end(),grades_arr);

	return median<double>(grades_arr,grades_arr+num_grades);
}

template <class Function>
void write_analysis(std::ostream &out, const std::string &name, Function grading_func, const std::vector<student_info> &did, const std::vector<student_info> &didnt)
{
	out << name << "; median(did) = " << analysis(did,grading_func) << ", median(didn't) = " << analysis(didnt,grading_func) << std::endl;
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
	write_analysis(std::cout, "median", grade_aux, did, didnt);
	write_analysis(std::cout, "average", average_grade, did, didnt);
	write_analysis(std::cout, "median of homework turned in", optimistic_median, did, didnt);

	return 0;
}
