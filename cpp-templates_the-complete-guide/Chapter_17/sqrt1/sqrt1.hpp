#pragma once

//primary template to compute sqrt(N)
template <int N, int LO=1, int HI=N>
class Sqrt
{
public:
	//compute the midpoint, rounded up
	enum { mid = (LO+HI+1)/2 };

	//search a not too large value in a halved interval
	enum { result = (N<mid*mid) ? Sqrt<N,LO,mid-1>::result : Sqrt<N,mid,HI>::result };
};

//partial specialization for the case when LO equals HI
template <int N, int M>
class Sqrt<N,M,M>
{
public:
	enum { result = M };
};
