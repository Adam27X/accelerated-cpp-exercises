#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "grade.h"

struct student_info
{
	std::string name;
	/*double midterm_exam, final_exam;
	std::vector<double> homework;*/
	double final_grade;
};

bool compare(const student_info &s, const student_info &t);
std::istream& read(std::istream& i, student_info &s);
std::istream& read_hw(std::istream& i, std::vector<double> &v);
