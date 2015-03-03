#include "t.hpp"

void helper(S<int>* s)
{
	s->f(); //First point of instantiation of S::f
}
