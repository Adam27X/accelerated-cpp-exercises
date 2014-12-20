#pragma once
#include <iostream>
#include <stdexcept>

#include "core.hpp"

class student_info
{
public:
	// constructors and copy control
	student_info(): cp(0) { }
	student_info(std::istream &is) : cp(0) { read(is); }
	student_info(const student_info &s);
	student_info& operator=(const student_info &s);
	~student_info() { delete cp; }

	// operations
	std::istream& read(std::istream &is);

	std::string name() const 
	{
		if(cp)
		{
			return cp->name();
		}
		else
		{
			throw std::runtime_error("Uninitialized student.");
		}
	}

	double grade() const
	{
		if(cp)
		{
			return cp->grade();
		}
		else
		{
			throw std::runtime_error("Uninitialized student.");
		}
	}

	bool valid() const
	{
		if(cp)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	static bool compare(const student_info &s1, const student_info &s2)
	{
		return s1.name() < s2.name();
	}

private:
	core *cp; //can represent either core or grad
};

std::istream& student_info::read(std::istream &is)
{
	delete cp; // delete previous object, if any

	char ch;
	is >> ch; // get record type

	if(ch == 'U')
	{
		cp = new core(is);
	}
	else
	{
		cp = new grad(is);
	}

	return is;
}

student_info::student_info(const student_info &s) : cp(0)
{
	if(s.cp)
	{
		cp = s.cp->clone();
	}
}

student_info& student_info::operator=(const student_info &s)
{
	if(&s != this)
	{
		delete cp;
		if(s.cp)
		{
			cp = s.cp->clone();
		}
		else
		{
			cp = 0;
		}
	}

	return *this;
}
