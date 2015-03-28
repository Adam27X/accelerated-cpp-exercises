#pragma once

#include "accumtraits4.hpp"
#include "sumpolicy1.hpp"

template <typename T,
	  typename Policy = SumPolicy,
	  typename Traits = AccumulationTraits<T> >
class Accum
{
public:
	typedef typename Traits::AccT AccT;
	static AccT accum(T const *beg, T const *end)
	{
		AccT total = Traits::zero();
		while(beg != end)
		{
			Policy::accumulate(total,*beg);
			++beg;
		}
		return total;
	}	
};

/*template <typename T>
inline typename AccumulationTraits<T>::AccT accum(T const *beg, T const *end)
{
	return Accum<T>::Accum(beg,end);
}

template<typename Traits, typename T>
inline typename Traits::AccT accum(T const *beg, T const *end)
{
	return Accum<T,Traits>::accum(beg,end);
}*/
