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
	double get_final_grade() const { return final_grade; } 
	bool valid() const { return !homework.empty(); }
	std::istream& read(std::istream &);
	double grade() const;

private:
	std::string n;
	double midterm_exam;
	double final_exam;
	std::vector<double> homework;
	double final_grade;
};

bool compare(const student_info &x, const student_info &y);
