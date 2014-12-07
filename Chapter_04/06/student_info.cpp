#include "student_info.h"

bool compare(const student_info &s, const student_info &t)
{
	return s.name < t.name;
}

std::istream& read(std::istream &i, student_info &s)
{
	//read and store the student's name and midterm and final exam grades
	double midterm_exam, final_exam;
	std::vector<double> hw;
	i >> s.name >> midterm_exam >> final_exam;

	read_hw(i,hw); //read and store all of the student's homework grades

	if(i)
	{
		s.final_grade = grade(midterm_exam,final_exam,hw);
	}

	return i;
}

std::istream& read_hw(std::istream &i, std::vector<double> &hw)
{
	if(i)
	{
		// get rid of previous contents
		hw.clear();

		// read homework grades
		double x;
		while(i >> x)
		{
			hw.push_back(x);
		}
		
		// clear the stream so that input will work for the next student
		i.clear();
	}

	return i;
}
