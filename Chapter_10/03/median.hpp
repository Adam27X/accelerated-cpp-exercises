#pragma once

#include <vector>
#include <algorithm>
#include <stdexcept>

template <class T, class RandomAccessIterator>
T median(RandomAccessIterator b, RandomAccessIterator e)
{
	if(b == e)
	{
		throw std::domain_error("Median of empty vector");
	}

	std::vector<T> temp(b,e);
	std::sort(temp.begin(),temp.end());

	size_t mid = temp.size()/2;

	
	T ret = (temp.size() % 2 == 0) ? (temp[mid] + temp[mid-1]) / 2 : temp[mid];

	return ret;
}
