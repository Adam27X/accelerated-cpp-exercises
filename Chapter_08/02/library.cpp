#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <climits>

// Avoid name collisions with the standard library
namespace test
{
	template <class InputIterator1, class InputIterator2>
	bool equal(InputIterator1 b, InputIterator1 e, InputIterator2 b2)
	{
		while(b != e)
		{
			if(*b++ != *b2++)
			{
				return false;
			}
		}

		return true;
	}

	template <class InputIterator, class Value>
	InputIterator find(InputIterator b, InputIterator e, const Value &t)
	{
		while(b != e)
		{
			if(*b == t)
			{
				return b;
			}
			++b;
		}

		return e;
	}
}

int main()
{
	std::vector<int> v;
	int x;

	std::cout << "Enter at least 5 elements: ";
	while(std::cin >> x)
	{
		v.push_back(x);
	}

	std::vector<int> v2(v);

	//Test equality
	std::cout << "Testing equal()." << std::endl;
	std::cout << "Equality: " << std::endl;
	std::cout << "std::equal(v,v2): " << std::equal(v.begin(),v.end(),v2.begin()) << std::endl;
	std::cout << "test::equal(v,v2): " << test::equal(v.begin(),v.end(),v2.begin()) << std::endl;
	
	for(unsigned i=0; i<v.size(); i++)
	{
		v2[i] = v[i]+1;
	}
	
	//Test inequality
	std::cout << "Inequality: " << std::endl;
	std::cout << "std::equal(v,v2): " << std::equal(v.begin(),v.end(),v2.begin()) << std::endl;
	std::cout << "test::equal(v,v2): " << test::equal(v.begin(),v.end(),v2.begin()) << std::endl;

	std::cout << std::endl;
	int key = v[2];

	std::cout << "Testing find()." << std::endl;
	std::cout << "Found (result != v.end()): " << std::endl;
	std::cout << "std::find(v,v[2]): " << (std::find(v.begin(),v.end(),key) == v.end()) << std::endl;
	std::cout << "test::find(v,v[2]): " << (test::find(v.begin(),v.end(),key) == v.end()) << std::endl;
	std::cout << "Not found (result == v.end()): " << std::endl;
	std::cout << "std::find(v,INT_MAX): " << (std::find(v.begin(),v.end(),INT_MAX) == v.end()) << std::endl;
	std::cout << "test::find(v,INT_MAX): " << (test::find(v.begin(),v.end(),INT_MAX) == v.end()) << std::endl;

	return 0;
}
