#include "student_info.h"

double grade(double midterm_exam, double final_exam)
{
        return 0.5*midterm_exam + 0.5*final_exam;
}

student_info::student_info() : midterm_exam(0), final_exam(0), letter_grade(' ') { }

student_info::student_info(std::istream &in) { read(in); }

std::istream& student_info::read(std::istream &in)
{
	in >> n >> midterm_exam >> final_exam;

	return in;	
}

double student_info::grade()
{
	double ret = ::grade(midterm_exam,final_exam);
	if(ret > 60)
	{
		letter_grade = 'P';
	}
	else
	{
		letter_grade = 'F';
	}
	return ret;
}

bool compare(const student_info &x, const student_info &y)
{
	return x.name() < y.name();
}
