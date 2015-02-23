#pragma once
#include <iostream>
#include <stdexcept>

#include "ptr.hpp"
#include "core.hpp"

class student_info
{
public:
	// constructors and copy control
	student_info() { }
	student_info(std::istream &is) { read(is); }

	// operations
	std::istream& read(std::istream &is);

	std::string name() const 
	{
		if(handle)
		{
			return handle->name();
		}
		else
		{
			throw std::runtime_error("Uninitialized student.");
		}
	}

	double grade() const
	{
		if(handle)
		{
			return handle->grade();
		}
		else
		{
			throw std::runtime_error("Uninitialized student.");
		}
	}

	static bool compare(const student_info &s1, const student_info &s2)
	{
		return s1.name() < s2.name();
	}

private:
	ptr<core> handle;
};

std::istream& student_info::read(std::istream &is)
{
	char ch;
	is >> ch; // get record type

	if(ch == 'U')
	{
		handle = new core(is);
	}
	else
	{
		handle = new grad(is);
	}

	return is;
}

