#include "student_info.h"

double median(std::vector<double> vec)
{
        typedef std::vector<double>::size_type vec_sz;

        vec_sz size = vec.size();
        if(size == 0)
        {
                throw std::domain_error("median of an empty vector");
        }

        std::sort(vec.begin(),vec.end());

        vec_sz mid = size/2;

        return size % 2 == 0 ? (vec[mid] + vec[mid-1])/2 : vec[mid];
}

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

student_info::student_info() : midterm_exam(0), final_exam(0) { }

student_info::student_info(std::istream &in) { read(in); }

std::istream& student_info::read_hw(std::istream &i)
{
        if(i)
        {
                // get rid of previous contents
                homework.clear();

                // read homework grades
                double x;
                while(i >> x)
                {
                        homework.push_back(x);
                }

                // clear the stream so that input will work for the next student
                i.clear();
        }

        return i;
}

std::istream& student_info::read(std::istream &in)
{
	in >> n >> midterm_exam >> final_exam;
	read_hw(in);

	return in;	
}

double student_info::grade() const
{
	return ::grade(midterm_exam,final_exam,homework);
}

bool compare(const student_info &x, const student_info &y)
{
	return x.name() < y.name();
}
