#include <iostream>
#include <vector>

namespace test
{
	template <class T>
	void swap(T &a, T &b)
	{
		T temp = a;
		a = b;
		b = temp;
	}

	template <class BidirectionalIterator>
	void reverse(BidirectionalIterator b, BidirectionalIterator e)
	{
		while(b != e)
		{
			--e;
			if(b != e)
			{
				//*b++ = *e;
				swap(*b++,*e);
			}
		}
	}
}

int main()
{
	std::string s("Hello world!");
	test::reverse(s.begin(),s.end());

	std::cout << "Reversed string: " << s << std::endl;

	return 0;
}
