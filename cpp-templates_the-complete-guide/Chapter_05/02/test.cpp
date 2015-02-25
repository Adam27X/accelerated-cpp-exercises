#include <iostream>
#include <vector>

#include "stackdecl.hpp"
#include "stackassign.hpp"

int main()
{
	Stack< int,std::vector<int> > intStack;
	intStack.push(7);
	
	//Can't use std::vector as the container here since std::vector has no push_front() method, which is needed by the assignment operator
	Stack<float> floatStack; 
	floatStack.push(7.77f);

	floatStack = intStack;

	std::cout << "floatStack.top(): " << floatStack.top() << std::endl;

	return 0;
}
