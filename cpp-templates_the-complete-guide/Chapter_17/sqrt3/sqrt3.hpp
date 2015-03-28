#pragma once

//primary template to compute sqrt(N)
template <int N, int I=1>
class Sqrt
{
public:
	enum { result = (I*I<N) ? Sqrt<N,I+1>::result : I };
};

//partial specialization for the case when LO equals HI
template <int N>
class Sqrt<N,N>
{
public:
	enum { result = N };
};
