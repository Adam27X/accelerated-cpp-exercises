#include <iostream>
#include <algorithm>
#include <vector>

namespace test
{
	template <class RandomAccessIterator, class X>
	bool binary_search(RandomAccessIterator begin, RandomAccessIterator end, const X &x)
	{
		while(begin < end)
		{
			// find the midpoint of the range
			RandomAccessIterator mid = begin + (end - begin) / 2;
			//RandomAccessIterator mid = (begin + end)/2; This line will not compile because we cannot meaningfully add two iterators together. Perhaps we could define operator+ for std::vector<int> this would work though.

			// see which part of the range contains x; keep looking only in that part
			if(x < *mid)
			{
				end = mid;
			}
			else if(*mid < x)
			{
				begin = mid + 1;
			}
			else
			{
				return true;
			}
		}

		return false;
	}
}

int main()
{
	std::vector<int> v;
	for(int i=1; i<11; i++)
	{
		v.push_back(2*i);
	}

	test::binary_search(v.begin(),v.end(),15) ? std::cout << "Test failed." : std::cout << "Test passed.";
	std::cout << std::endl;
	test::binary_search(v.begin(),v.end(),14) ? std::cout << "Test passed." : std::cout << "Test failed.";
	std::cout << std::endl;

}
