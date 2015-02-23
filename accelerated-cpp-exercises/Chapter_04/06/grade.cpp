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

