#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>

int main()
{
	int students;
	std::cout << "Enter the number of students: " << std::endl;
	std::cin >> students;
	
	const int num_hws = 5; //Assume 5 hws per student

	//print output
	for(int i=0; i<students; i++)
	{
		double midterm_exam = rand() % 101; //Range 0 to 100
		double final_exam = rand() % 101;
		std::vector<int> hw(num_hws);
		for(unsigned j=0; j<hw.size(); j++)
		{
			hw[j] = rand() % 101;
		}

		std::string name = "";
		for(unsigned j=0; j<5; j++)
		{
			char tmp = rand() % 26 + 97;
			name += tmp;
		}

		std::cout << name << " " << midterm_exam << " " << final_exam << " ";
		for(unsigned j=0; j<hw.size(); j++)
		{
			std::cout << hw[j] << " ";
		}
		std::cout << std::endl;
	}
}
