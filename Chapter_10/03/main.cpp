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
	std::vector<student_info> record;
	student_info student;

	while(read(std::cin,student))
	{
		record.push_back(student);
	}

	double *hw_arr = new double[5];
	for(std::vector<student_info>::iterator i=record.begin();i!=record.end(); ++i)
	{
		std::vector<double> hw = i->homework;
		std::cout << "Testing vector: " << std::endl;
		if(hw.size())
		{
			std::cout << "hw before: [" << hw[0];
			for(std::vector<double>::iterator j=hw.begin()+1;j!=hw.end();++j)
			{
				std::cout << "," << *j;	
			}
			std::cout << "]" << std::endl;
			double med = median<double>(hw.begin(),hw.end());
			std::cout << "Median: " << med << std::endl;
			std::cout << "hw after: [" << hw[0];
			for(std::vector<double>::iterator j=hw.begin()+1;j!=hw.end();++j)
			{
				std::cout << "," << *j;	
			}
			std::cout << "]" << std::endl;
		}
		std::copy(hw.begin(),hw.end(),hw_arr);
		break;
	}

	std::cout << "Testing array: " << std::endl;
	std::cout << "hw before: [" << hw_arr[0];
	for(int j=1; j<5; j++)
	{
		std::cout << "," << hw_arr[j];
	}
	std::cout << "]" << std::endl;
	double med = median<double>(hw_arr,hw_arr+5);
	std::cout << "Median: " << med << std::endl;
	std::cout << "hw after: [" << hw_arr[0];
	for(int j=1; j<5; j++)
	{
		std::cout << "," << hw_arr[j];
	}
	std::cout << "]" << std::endl;

	return 0;
}
