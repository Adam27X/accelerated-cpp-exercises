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

std::string letter_grade(double grade)
{
        // range posts for numeric grades
        static const double numbers[] = {
                97, 94, 90, 87, 84, 80, 77, 74, 70, 60, 0
        };

        // names for the letter grades
        static const char* const letters[] = {
                "A+", "A", "A-", "B+", "B", "B-", "C+", "C", "C-", "D", "F"
        };

        // compute the number of grades given the size of the array
        // and the size of a single element
        static const size_t ngrades = sizeof(numbers)/sizeof(*numbers);

        // given a numeric grade, find and return the associated letter grade
        for(size_t i=0; i<ngrades; ++i)
        {
                if(grade >= numbers[i])
                {
                        return letters[i];
                }
        }

        return "?\?\?";
}

class core
{
	friend class student_info;
public:
	core(): midterm_exam(0), final_exam(0) { }
	core(std::istream& is) { read(is); }
	//tells delete to use the proper destructor when deleting points to core/grad objects
	//needed whenever a derived type is destoryed via a pointer to base
	virtual ~core() { } 
	
	std::string name() const;

	virtual std::istream& read(std::istream &is);
	virtual double grade() const;
	virtual std::string get_letter_grade() const;
	virtual bool met_all_requirements() const;

protected:
	// accessible to derived classes
	std::istream& read_common(std::istream &is);
	double midterm_exam;
	double final_exam;
	std::vector<double> homework;
	virtual core* clone() const { return new core(*this); } 
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

std::string core::get_letter_grade() const
{
	double final_grade = grade();
	return letter_grade(final_grade);
}

bool core::met_all_requirements() const
{
	return ((std::find(homework.begin(),homework.end(),0)) == homework.end());
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
	grad(): thesis(0) { }
	grad(std::istream &is) { read(is); }

	// grade and read are virtual by inheritance
	std::istream& read(std::istream &is);
	double grade() const;
	std::string get_letter_grade() const;
	bool met_all_requirements() const;

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

std::string grad::get_letter_grade() const
{
	double final_grade = grade(); //grade() here refers to grad::grade()
	return letter_grade(final_grade);
}

bool grad::met_all_requirements() const
{
	return ((core::met_all_requirements()) && (thesis > 0.0));
}

class pass_fail: public core
{
public:
	pass_fail() { }
	pass_fail(std::istream &is) { core::read(is); }

	double grade() const;
	std::string get_letter_grade() const;
	bool met_all_requirements() const;

protected:
	pass_fail* clone() const { return new pass_fail(*this); }
};

double pass_fail::grade() const
{
	if(homework.empty())
	{
		return (midterm_exam + final_exam)/2;
	}
	else
	{
		return core::grade();
	}
}

std::string pass_fail::get_letter_grade() const
{
	double final_grade = grade();
	if(final_grade >= 60)
	{
		return "Pass";
	}
	else
	{
		return "Fail";
	}
}

bool pass_fail::met_all_requirements() const
{
	return true;
}

class audit: public core
{
public:
	audit() { }
	audit(std::istream &is) { is >> n; }
	double grade() const { return 0.0; } 
	std::string get_letter_grade() const;
	bool met_all_requirements() const { return true; }
protected:
	audit* clone() const { return new audit(*this); }	
};

std::string audit::get_letter_grade() const
{
	return "Audit";
}
