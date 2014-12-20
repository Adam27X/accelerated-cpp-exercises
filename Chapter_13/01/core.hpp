#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>

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

class core
{
	friend class student_info;
public:
	core(): midterm_exam(0), final_exam(0) { std::cerr << "core()" << std::endl; }
	core(std::istream& is) { read(is); std::cerr << "core(std::istream&)" << std::endl; }
	//tells delete to use the proper destructor when deleting points to core/grad objects
	//needed whenever a derived type is destoryed via a pointer to base
	virtual ~core() { } 
	
	std::string name() const;

	virtual std::istream& read(std::istream &is);
	virtual double grade() const;

protected:
	// accessible to derived classes
	std::istream& read_common(std::istream &is);
	double midterm_exam;
	double final_exam;
	std::vector<double> homework;
	virtual core* clone() const { return new core(*this); } 

private:
	// accessible only to core
	std::string n;
};

std::string core::name() const
{
	return n;
}

double core::grade() const
{
	return ::grade(midterm_exam,final_exam,homework);
}

std::istream& core::read_common(std::istream &in)
{
	// read and share the student's name and exam grades
	in >> n >> midterm_exam >> final_exam;
	return in;
}

std::istream& core::read(std::istream &in)
{
	read_common(in);
	read_hw(in,homework);
	return in;
}

class grad: public core
{
public:
	grad(): thesis(0) { std::cout << "grad()" << std::endl; }
	grad(std::istream &is) { read(is); std::cout << "grad(std::istream&)" << std::endl; }

	// grade and read are virtual by inheritance
	std::istream& read(std::istream &is);
	double grade() const;

protected:
	grad* clone() const { return new grad(*this); }	

private:
	double thesis;
};

std::istream& grad::read(std::istream &is)
{
	read_common(is); //inherited from core, so same as core::read_common()
	is >> thesis;
	read_hw(is,homework);
	return is;
}

double grad::grade() const
{
	return std::min(core::grade(),thesis); //Here we need to explicitly qualify core to prevent recursive calls to grad::grade()
}
