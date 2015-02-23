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
	bool valid() const { return !homework.empty(); }
	std::istream& read(std::istream &);
	double grade() const;
	void print_statistics();

	student_info(const student_info &s);
	student_info& operator=(const student_info &);
	~student_info() { destroyed_count++; }

private:
	std::string n;
	double midterm_exam;
	double final_exam;
	std::vector<double> homework;
	
	//Instrument with metrics - made static so that they're shared across object instances
	static int constructed_count;
	static int copied_count;
	static int assigned_count;
	static int destroyed_count;
};

bool compare(const student_info &x, const student_info &y);
