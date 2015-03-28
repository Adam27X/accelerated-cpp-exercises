#include "rparam.hpp"
#include "rparamcls.hpp"

//function that allows parameter passing by value or by reference
template<typename T1, typename T2>
void foo_core(typename RParam<T1>::Type p1, typename RParam<T2>::Type p2)
{

}

//wrapper to avoid explicit template parameter passing
template<typename T1, typename T2>
inline void foo(T1 const &p1, T2 const &p2)
{
	foo_core<T1,T2>(p1,p2);
}

int main()
{
	MyClass1 mc1;
	MyClass2 mc2;
	foo(mc1,mc2);

	return 0;
} 
