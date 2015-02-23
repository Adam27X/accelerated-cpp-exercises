#include <iostream>
#include <iomanip>
#include <ios>
#include <string>

int main()
{
	// ask for and read the student's name
	std::cout << "Please enter your first name: ";
	std::string name;
	std::cin >> name;
	std::cout << "Hello, " << name << "!" << std::endl;

	// ask for and read the midterm and final grades
	std::cout << "Please enter your midterm and final exam grades: ";
	double midterm_exam, final_exam;
	std::cin >> midterm_exam >> final_exam;

	// ask for the homework grades
	std::cout << "Enter all your homework grades, followed by end-of-file: ";

	// the number and sum of grades read so far
	int count = 0;
	double sum = 0;

	// a variable into which to read
	double x;

	// invariant:
	// we have read count grades so far, and sum is the sum of the first count grades
	while(std::cin >> x)
	{
		++count;
		sum += x;
	}

	if(count == 0)
	{
		std::cout << "Error, no grades read!" << std::endl;
		return 1;
	}

	// write the result
	std::streamsize prec = std::cout.precision();
	std::cout << "Your final grade is " << std::setprecision(3) << 0.2*midterm_exam + 0.4*final_exam + 0.4*sum/count << std::setprecision(prec) << std::endl;

	return 0;
}
