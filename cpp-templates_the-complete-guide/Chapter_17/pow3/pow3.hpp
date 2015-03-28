#pragma once

//primary template to compute 3 to the Nth
template<int N>
class Pow3
{
public:
	enum { result = 3 * Pow3<N-1>::result };
};

//full specialization to end the recursion
template <>
class Pow3<0>
{
public:
	enum { result = 1 };
};
