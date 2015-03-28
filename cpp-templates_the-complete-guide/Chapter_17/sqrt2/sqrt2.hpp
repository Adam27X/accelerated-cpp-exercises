#pragma once

#include "ifthenelse.hpp"

//primary template to compute sqrt(N)
template <int N, int LO=1, int HI=N>
class Sqrt
{
public:
	//compute the midpoint, rounded up
	enum { mid = (LO+HI+1)/2 };

	//search a not too large value in a halved interval
	typedef typename IfThenElse<(N<mid*mid),
				    Sqrt<N,LO,mid-1>,
				    Sqrt<N,mid,HI> >::ResultT SubT;
	enum { result = SubT::result };
};

//partial specialization for the case when LO equals HI
template <int N, int S>
class Sqrt<N,S,S>
{
public:
	enum { result = S };
};
