#include <stdexcept>
#include <vector>

#include "grade.h"
#include "median.h"
#include "student_info.h"

double grade(double midterm_exam, double final_exam, double homework)
{
	return 0.2*midterm_exam + 0.4*final_exam + 0.4*homework;
}

double grade(double midterm_exam, double final_exam, const std::vector<double> &hw)
{
	if(hw.size() == 0)
	{
		throw std::domain_error("Student has done no homework.");
	}

	return grade(midterm_exam, final_exam, median(hw));
}

double grade(const student_info &s)
{
	return grade(s.midterm_exam,s.final_exam,s.homework);
}

char grade_letter(const student_info &s)
{
	double num = grade(s);
	if(num >= 90)
	{
		return 'A';
	}
	else if(num >= 80)
	{
		return 'B';
	}
	else if(num >= 70)
	{
		return 'C';
	}
	else if(num >= 60)
	{
		return 'D';
	}
	
	return 'F';
}
