#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>
#include <iomanip>

#include "core.hpp"
#include "ptr.hpp"

bool compare_core_ptrs(const ptr<core> &l, const ptr<core> &r)
{
	return l->name() < r->name();
}

int main()
{
	std::vector< ptr<core> > students;
	ptr<core> record;
	char ch;
	std::string::size_type maxlen = 0;

	// read and store the data
	while(std::cin >> ch)
	{
		if(ch == 'U')
		{
			record = new core;
		}
		else
		{
			record = new grad;
		}

		record->read(std::cin); // ptr<T>::->, then virtual call to read
		maxlen = std::max(maxlen,record->name().size()); // ptr<T>::->
		students.push_back(record);
	}

	// alphabetize the student records
	sort(students.begin(),students.end(),compare_core_ptrs);

	// write the names and grades
	for(std::vector< ptr<core> >::size_type i=0; i!=students.size(); ++i)
	{
		std::cout << students[i]->name() << std::string(maxlen + 1 - students[i]->name().size(), ' ');
		try
		{
			double final_grade = students[i]->grade();
			std::streamsize prec = std::cout.precision();
			std::cout << std::setprecision(3) << final_grade << std::setprecision(prec) << std::endl;
		}
		catch(std::domain_error e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	return 0;
}
