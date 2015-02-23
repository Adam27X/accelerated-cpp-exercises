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
	std::string name() { return n; } // Making this non-const means that n must be public
	bool valid() const { return !homework.empty(); }
	std::istream& read(std::istream &);
	double grade() const;
	std::string n;

private:
	double midterm_exam;
	double final_exam;
	std::vector<double> homework;
};

bool compare(const student_info &x, const student_info &y); //This function must now use n instead of name since name is non-const
