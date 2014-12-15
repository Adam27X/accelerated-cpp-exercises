#pragma once

#include <vector>
#include "student_info.h"

double grade(double midterm_exam, double final_exam, double homework);
double grade(double midterm_exam, double final_exam, const std::vector<double> &hw);
double grade(const student_info &s);
