#include <iostream>

class NotVirtual
{ };

class Virtual
{
public:
	virtual void foo() { }
};

template <typename VBase>
class Base : private VBase
{
public:
	//the virtuality of foo() depends on its declaration
	//(if any) in the base class VBase
	void foo()
	{
		std::cout << "Base::foo()" << "\n";
	}
};

template <typename V>
class Derived : public Base<V>
{
public:
	void foo()
	{
		std::cout << "Derived::foo()" << "\n";
	}
};

int main()
{
	Base<NotVirtual>* p1 = new Derived<NotVirtual>;
	p1->foo(); //calls Base::foo()

	Base<Virtual>* p2 = new Derived<Virtual>;
	p2->foo(); //calls Derived::foo()
	
	return 0;
}
