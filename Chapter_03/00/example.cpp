#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

int main()
{
	// ask for and read the student's name
	std::cout << "Please enter your first name: ";
	std::string name;
	std::cin >> name;
	std::cout << "Hello, " << name << "!" << std::endl;

	// ask for and read the midterm and final grades
	std::cout << "Please enter your midterm and final exam grades: ";
	double midterm_exam, final_exam; //Final is a reserved keyword so we append _exam
	std::cin >> midterm_exam >> final_exam;

	// ask for and read the homework grades
	std::cout << "Enter your homework grades, "
		     "followed by end-of-file: ";

	std::vector<double> homework;
	double x;
	// invariant: homework contains all the homework grades read so far
	while(std::cin >> x)
	{
		homework.push_back(x);
	}

	// check that the student entered at least one hw grade
	typedef std::vector<double>::size_type vec_sz;
	vec_sz size = homework.size();
	if(size == 0)
	{
		std::cout << std::endl << "You must enter your grades. Please try again." << std::endl;
		return 1;
	}

	// sort the grades
	std::sort(homework.begin(),homework.end());
	
	// compute the median hw grade
	vec_sz mid = size/2;
	double median;
	median = size % 2 == 0 ? (homework[mid] + homework[mid-1])/2 : homework[mid];

	// compute and write final grade
	std::streamsize prec = std::cout.precision();
	std::cout << "Your final grade is " << std::setprecision(3) << 0.2*midterm_exam + 0.4*final_exam + 0.4*median << std::setprecision(prec) << std::endl;

	return 0;
}
