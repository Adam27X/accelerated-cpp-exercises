#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <algorithm>

class student_info
{
public:
	student_info(); // construct an empty student info object
	student_info(std::istream &in); // construct an object by reading in a stream
	std::string name() const { return n; }
	double get_final_grade() const {return final_grade; }
	char get_letter_grade() const { return letter_grade; }
	std::istream& read(std::istream &);
	double grade();

private:
	std::string n;
	double midterm_exam;
	double final_exam;
	double final_grade;
	char letter_grade;
};

bool compare(const student_info &x, const student_info &y);
