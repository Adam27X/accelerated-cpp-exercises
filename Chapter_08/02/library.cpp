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

	//ForwardIterators are needed here because we make repeated passes through both containers
	template <class ForwardIterator1, class ForwardIterator2>
	ForwardIterator1 search(ForwardIterator1 b, ForwardIterator1 e, ForwardIterator2 b2, ForwardIterator2 e2)
	{
		while(b != e)
		{
			ForwardIterator1 it1 = b;
			ForwardIterator2 it2 = b2;
			while(*it1 == *it2)
			{
				++it1;
				++it2;
				if(it2 == e2)
				{
					return b;
				}
				else if(it1 == e)
				{
					return e;
				}
			}
			++b;
		}

		return e;	
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

	template <class InputIterator, class UnaryPredicate>
	InputIterator find_if(InputIterator b, InputIterator e, UnaryPredicate p)
	{
		while(b != e)
		{
			if(p(*b))
			{
				return b;
			}
			++b;
		}
		
		return e;
	}

	template <class InputIterator, class OutputIterator>
	OutputIterator copy(InputIterator b, InputIterator e, OutputIterator d)
	{
		while(b != e)
		{
			*d++ = *b++;
		}

		return d;
	}

	template <class InputIterator, class OutputIterator, class Value>
	OutputIterator remove_copy(InputIterator b, InputIterator e, OutputIterator d, const Value &t)
	{
		while(b != e)
		{
			if(*b != t)
			{
				*d++ = *b;
			}
			b++;
		}

		return d;
	}

	template <class InputIterator, class OutputIterator, class UnaryPredicate>
	OutputIterator remove_copy_if(InputIterator b, InputIterator e, OutputIterator d, UnaryPredicate p)
	{
		while(b != e)
		{
			if(!p(*b))
			{
				*d++ = *b;
			}
			b++;
		}

		return d;
	}

	template <class ForwardIterator, class Value>
	ForwardIterator remove(ForwardIterator b, ForwardIterator e, const Value &t)
	{
		ForwardIterator it = b;
		while(it != e)
		{
			if(*it != t)
			{
				*b++ = *it;
			}
			it++;
		}

		return b;
	}

	template <class InputIterator, class OutputIterator, class UnaryFunction>
	OutputIterator transform(InputIterator b, InputIterator e, OutputIterator d, UnaryFunction f)
	{
		while(b != e)
		{
			*d++ = f(*b);
			b++;
		}

		return d;
	}

	template <class ForwardIterator, class UnaryPredicate>
	ForwardIterator partition(ForwardIterator b, ForwardIterator e, UnaryPredicate p)
	{
		ForwardIterator first_fail = b;
		while(b != e)
		{
			if(p(*b))
			{
				std::swap(*first_fail++,*b);
			}
			b++;
		}

		return first_fail;
	}

	template <class InputIterator, class Value>
	Value accumulate(InputIterator b, InputIterator e, const Value &t)
	{
		Value ret = t;
		while(b != e)
		{
			ret += *b++;
		}

		return ret;
	}
}

bool is_zero(int c)
{
	return c == 0;
}

bool is_not_zero(int c)
{
	return c!=0;
}

int axpy(int c)
{
	return 2*c + 3;	
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
	
	std::cout << std::endl << "Testing search()." << std::endl;
	std::cout << "Not found: " << std::endl;
	std::cout << "std::search(v,v2): " << (std::search(v.begin(),v.end(),v2.begin(),v2.end()) == v.end()) << std::endl;
	std::cout << "test::search(v,v2): " << (test::search(v.begin(),v.end(),v2.begin(),v2.end()) == v.end()) << std::endl;
	std::vector<int> v3(v2);
	v3.insert(v3.end(),v.begin(),v.end());
	std::cout << "Found: " << std::endl;
	std::cout << "std::search(v3,v): " << (std::search(v3.begin(),v3.end(),v.begin(),v.end()) == v3.end()) << std::endl;
	std::cout << "test::search(v3,v): " << (test::search(v3.begin(),v3.end(),v.begin(),v.end()) == v3.end()) << std::endl;

	std::cout << std::endl;
	int key = v[2];

	std::cout << "Testing find()." << std::endl;
	std::cout << "Found (result != v.end()): " << std::endl;
	std::cout << "std::find(v,v[2]): " << (std::find(v.begin(),v.end(),key) == v.end()) << std::endl;
	std::cout << "test::find(v,v[2]): " << (test::find(v.begin(),v.end(),key) == v.end()) << std::endl;
	std::cout << "Not found (result == v.end()): " << std::endl;
	std::cout << "std::find(v,INT_MAX): " << (std::find(v.begin(),v.end(),INT_MAX) == v.end()) << std::endl;
	std::cout << "test::find(v,INT_MAX): " << (test::find(v.begin(),v.end(),INT_MAX) == v.end()) << std::endl;

	std::cout << std::endl << "Testing find_if()." << std::endl;
	std::cout << "Not Found (result == v.end()): " << std::endl;
	std::cout << "std::find_if(v,is_zero): " << (std::find_if(v.begin(),v.end(),is_zero) == v.end()) << std::endl;
	std::cout << "test::find(v,is_zero): " << (test::find_if(v.begin(),v.end(),is_zero) == v.end()) << std::endl;
	std::cout << "Found (result != v.end()): " << std::endl;
	std::cout << "std::find_if(v,is_not_zero): " << (std::find_if(v.begin(),v.end(),is_not_zero) == v.end()) << std::endl;
	std::cout << "test::find(v,is_not_zero: " << (test::find_if(v.begin(),v.end(),is_not_zero) == v.end()) << std::endl;

	std::cout << std::endl << "Testing copy()." << std::endl;
	std::vector<int> v4;
	test::copy(v.begin(),v.end(),std::back_inserter(v4));
	test::equal(v.begin(),v.end(),v4.begin()) ? std::cout << "Pass." : std::cout << "Fail.";
	std::cout << std::endl;

	std::cout << std::endl << "Testing remove_copy()." << std::endl;
	v4.clear();
	test::remove_copy(v.begin(),v.end(),std::back_inserter(v4),key);
	test::find(v4.begin(),v4.end(),key) == v4.end() ? std::cout << "Pass." : std::cout << "Fail.";
	std::cout << std::endl;	

	std::cout << std::endl << "Testing remove_copy_if()." << std::endl;
	v4.clear();
	test::remove_copy_if(v.begin(),v.end(),std::back_inserter(v4),is_zero);
	test::find_if(v4.begin(),v4.end(),is_zero) == v4.end() ? std::cout << "Pass." : std::cout << "Fail.";
	std::cout << std::endl;

	std::cout << std::endl << "Testing remove()." << std::endl;
	test::remove(v4.begin(),v4.end(),0) == v4.end() ? std::cout << "Pass." : std::cout << "Fail.";
	std::cout << std::endl;

	std::cout << std::endl << "Testing transform()." << std::endl;
	v3.clear();
	v4.clear();
	std::transform(v.begin(),v.end(),std::back_inserter(v3),axpy);
	test::transform(v.begin(),v.end(),std::back_inserter(v4),axpy);
	std::equal(v3.begin(),v3.end(),v4.begin()) ? std::cout << "Pass." : std::cout << "Fail.";
	std::cout << std::endl;

	std::cout << std::endl << "Testing partition()." << std::endl;
	v3.clear();
	v3.push_back(1);
	v3.push_back(0);
	test::partition(v3.begin(),v3.end(),is_zero);
	v3[0] == 0 ? std::cout << "Pass." : std::cout << "Fail.";
	std::cout << std::endl;

	std::cout << std::endl << "Testing accumulate()." << std::endl;
	v3.clear();
	v3.push_back(1);
	v3.push_back(3);
	v3.push_back(6);
	test::accumulate(v3.begin(),v3.end(),0) == 10 ? std::cout << "Pass." : std::cout << "Fail.";
	std::cout << std::endl;

	return 0;
}
