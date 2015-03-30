#include <iostream>

#include "typet.hpp"

class MyClass { };
void myfunc() { }
enum E { e1 };

//check by passing type as template argument
template <typename T>
void check()
{
	if(TypeT<T>::IsFundaT)
	{
		std::cout << " IsFundaT ";
	}
	if(TypeT<T>::IsPtrT)
	{
		std::cout << " IsPtrT ";
	}
	if(TypeT<T>::IsRefT)
	{
		std::cout << " IsRefT ";
	}
	if(TypeT<T>::IsArrayT)
	{
		std::cout << " IsArrayT ";
	}
	if(TypeT<T>::IsFuncT)
	{
		std::cout << " IsFuncT ";
	}
	if(TypeT<T>::IsPtrMemT)
	{
		std::cout << " IsPtrMemT ";
	}
	if(TypeT<T>::IsEnumT)
	{
		std::cout << " IsEnumT ";
	}
	if(TypeT<T>::IsClassT)
	{
		std::cout << " IsClassT ";
	}
	std::cout << std::endl;
}

//check by passing type as function call argument
template <typename T>
void checkT(T)
{
	check<T>();

	//for pointer types check type of what they refer to
	if(TypeT<T>::IsPtrT || TypeT<T>::IsPtrMemT)
	{
		check<typename CompoundT<T>::BaseT>();
	}
}

int main()
{
	std::cout << "int:" << std::endl;
	check<int>();

	std::cout << "int&" << std::endl;
	check<int&>();

	std::cout << "char[42]:" << std::endl;
	check<char[42]>();

	std::cout << "MyClass:" << std::endl;
	check<MyClass>();

	std::cout << "ptr to enum:" << std::endl;
	E *ptr = 0;
	checkT(ptr);

	std::cout << "42:" << std::endl;
	checkT(42);

	std::cout << "myfunc():" << std::endl;
	checkT(myfunc);

	std::cout << "memptr to array:" << std::endl;
	char (MyClass::* memptr) [] = 0;
	checkT(memptr);

	return 0;
}
