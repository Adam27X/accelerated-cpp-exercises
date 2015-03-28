#pragma once

#include "accumtraits4.hpp"

template<typename T>
inline typename AccumulationTraits<T>::AccT accum(T const *beg, T const *end)
{
	//return type is traits of the element type
	typedef typename AccumulationTraits<T>::AccT AccT;

	AccT total = AccumulationTraits<T>::zero();
	while(beg != end)
	{
		total += *beg;
		++beg;
	}

	return total;
}
