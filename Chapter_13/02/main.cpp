#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>
#include <iomanip>

#include "core.hpp"
#include "student_info.hpp"

int main()
{
	core *p1 = new core;
	core *p2 = new grad;
	core s1;
	grad s2;

	std::cout << "p1->grade(): "; //core::grade
	try
	{
		p1->grade();
	}
	catch(std::domain_error e) { }
	std::cout << "p1->name(): "; //core::name
	p1->name();

	std::cout << "p2->grade(): "; //grad::grade
	try
	{
		p2->grade();
	}
	catch(std::domain_error e) { }
	std::cout << "p2->name(): "; //core::name
	p2->name();

	std::cout << "s1.grade(): "; //core::grade
	try
	{
		s1.grade();
	}
	catch(std::domain_error e) { }
	std::cout << "s1.name(): "; //core::name
	s1.name();

	std::cout << "s2.grade(): "; //grad::grade
	try
	{
		s2.grade();
	}
	catch(std::domain_error e) { }
	std::cout << "s2.name(): "; //core::name
	s2.name();

	return 0;
}
