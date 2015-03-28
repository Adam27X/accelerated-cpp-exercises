#pragma once

#include "ifthenelse.hpp"

//template to yield template argument as result
template <int N>
class Value
{
public:
	enum { result = N };
};

//template to compute sqrt(N) via iteration
template <int N, int I=1>
class Sqrt
{
public:
	//instantiate next step or result type as branch
	typedef typename IfThenElse<(I*I<N),
				    Sqrt<N,I+1>,
				    Value<I> >::ResultT SubT;
	enum { result = SubT::result };
};
