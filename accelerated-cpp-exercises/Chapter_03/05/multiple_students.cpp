#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

int main()
{
	// ask for and read the student's name
	std::cout << "Please enter a student name: ";
	std::string name;
	std::vector<std::string> names;
	std::vector<double> final_grades;
	const int num_homeworks = 4;
	while(std::cin >> name)
	{
		names.push_back(name);
		// ask for and read the midterm and final grades
		std::cout << "Please enter the midterm and final exam and the " << num_homeworks << " homework grades for each student: ";
		double midterm_exam, final_exam, hw; //Final is a reserved keyword so we append _exam
		std::vector<double> homeworks;
		std::cin >> midterm_exam >> final_exam;

		for(int i=0; i<num_homeworks; i++)
		{
			std::cin >> hw;
			homeworks.push_back(hw);
		}
		
		// sort the grades
		std::sort(homeworks.begin(),homeworks.end());
		
		// compute the median hw grade
		unsigned mid = num_homeworks/2;
		double median;
		median = num_homeworks % 2 == 0 ? (homeworks[mid] + homeworks[mid-1])/2 : homeworks[mid];
		double final_grade = 0.2*midterm_exam + 0.4*final_exam + 0.4*median;
		final_grades.push_back(final_grade);
		std::cout << "Enter another student's name if desired: ";
	}


	// compute and write final grade
	std::streamsize prec = std::cout.precision();
	std::cout <<  std::setprecision(3) << std::endl;
	for(unsigned i=0; i<names.size(); i++)
	{
		std::cout << "Final grade for " << names[i] << ": " << final_grades[i] << std::endl;
	}
	std::cout << std::setprecision(prec);

	return 0;
}
