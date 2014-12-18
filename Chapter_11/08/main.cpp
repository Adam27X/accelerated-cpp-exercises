#include <iostream>
#include <vector>

#include "linked_list.hpp"

int main()
{
	int arr[] = {1,2,3,4,5};
	linked_list<int> test(arr,arr+5);

	std::cout << "Testing linked_list::size(): ";
	test.size() == 5 ? std::cout << "Pass." : std::cout << "Fail.";
	std::cout << std::endl;

	std::cout << "Testing iterators: " << std::endl;
	for(linked_list<int>::const_iterator i=test.begin(); i!=test.end(); i++)
	{
		if(i == test.begin())
		{
			std::cout << *i;
		}
		else
		{
			std::cout << " -> " << *i;
		}
	}
	std::cout << std::endl;

	return 0;
}
