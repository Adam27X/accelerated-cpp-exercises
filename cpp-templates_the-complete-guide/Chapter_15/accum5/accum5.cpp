#include "accum5.hpp"
#include <iostream>

int main()
{
	//create array of 5 integer values
	int num[] = {1,2,3,4,5};
	
	//print average value
	std::cout << "The average value of the integer values is: " << accum(&num[0],&num[5])/5 << "\n";

	//create array of character values
	char name[] = "templates";
	int length = sizeof(name)-1;

	//(try to) print average character value
	std::cout << "The average value of the characters in \"" << name << "\" is " << accum(&name[0],&name[length])/length << "\n";

	return 0;
}
