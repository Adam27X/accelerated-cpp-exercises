#include "student_info.h"

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

int student_info::constructed_count = 0;
int student_info::copied_count = 0;
int student_info::assigned_count = 0;
int student_info::destroyed_count = 0;

student_info::student_info() : midterm_exam(0), final_exam(0) { constructed_count++; }

student_info::student_info(std::istream &in) { read(in); constructed_count++; }

student_info::student_info(const student_info &s)
{
	midterm_exam = s.midterm_exam;
	n = s.n;
	final_exam = s.final_exam;
	homework = s.homework;
	copied_count++;
}

student_info& student_info::operator=(const student_info &rhs)
{
	// check for self assignment
	if(&rhs != this)
	{
		midterm_exam = rhs.midterm_exam;
		final_exam = rhs.final_exam;
		n = rhs.n;
		homework = rhs.homework;
	}

	assigned_count++;

	return *this;
}

std::istream& student_info::read(std::istream &in)
{
	in >> n >> midterm_exam >> final_exam;
	read_hw(in, homework);

	return in;	
}

double student_info::grade() const
{
	return ::grade(midterm_exam,final_exam,homework);
}

void student_info::print_statistics()
{
	std::cout << "Number of objects created: " << constructed_count << std::endl;
	std::cout << "Number of objects copied: " << copied_count << std::endl;
	std::cout << "Number of objects assigned: " << assigned_count << std::endl;
	std::cout << "Number of objects destroyed: " << destroyed_count << std::endl;
}

bool compare(const student_info &x, const student_info &y)
{
	return x.name() < y.name();
}
