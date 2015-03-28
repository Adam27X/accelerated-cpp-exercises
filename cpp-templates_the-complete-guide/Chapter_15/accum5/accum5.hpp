#pragma once

#include "accumtraits4.hpp"

template <typename T, typename AT = AccumulationTraits<T> >
class Accum
{
public:
	static typename AT::AccT accum(T const *beg, T const *end)
	{
		typename AT::AccT total = AT::zero();
		while(beg != end)
		{
			total += *beg;
			++beg;
		}

		return total;
	}
};

template <typename T>
inline typename AccumulationTraits<T>::AccT accum (T const *beg, T const *end)
{
	return Accum<T>::accum(beg,end);
}
