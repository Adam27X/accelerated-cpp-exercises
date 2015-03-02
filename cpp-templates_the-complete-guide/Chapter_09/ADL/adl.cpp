#include <iostream>

namespace X
{
	template <typename T> void f(T);
}

namespace N
{
	using namespace X;
	enum E { e1 };
	void f(E e)
	{
		std::cout << "N::f(N::E e) called \n";
	}
}

void f(int x)
{
	std::cout << "::f(int x) called \n";
}

int main()
{
	::f(N::e1); //qualified function name, no ADL
	f(N::e1); //ordinary lookup finds ::f() and ADL finds N::f(); the latter is preferred

	return 0;
}
