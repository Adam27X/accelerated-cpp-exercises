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
	std::istream& read(std::istream &);
	double grade();
	char get_letter_grade() const { return letter_grade; }

private:
	std::string n;
	double midterm_exam;
	double final_exam;
	char letter_grade;
};

bool compare(const student_info &x, const student_info &y);
