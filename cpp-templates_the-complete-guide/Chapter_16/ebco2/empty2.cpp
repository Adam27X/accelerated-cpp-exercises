#include <iostream>

class EmptyClass
{
	typedef int Int; //typedef members don't make a class nonempty
};

class EmptyToo : public EmptyClass
{ };

class EmptyThree : public EmptyToo
{ };

int main()
{
	std::cout << "sizeof(EmptyClass): " << sizeof(EmptyClass) << std::endl;
	std::cout << "sizeof(EmptyToo): " << sizeof(EmptyToo) << std::endl;
	std::cout << "sizeof(EmptyThree): " << sizeof(EmptyThree) << std::endl;

	return 0;
}
