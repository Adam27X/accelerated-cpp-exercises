#include <iostream>

#include "objectcounter.hpp"

template <typename CharT>
class MyString : public ObjectCounter<MyString<CharT> > 
{

};

int main()
{
	MyString<char> s1, s2;
	MyString<wchar_t> ws;

	std::cout << "Number of MyString<char>: " << MyString<char>::live() << std::endl;
	std::cout << "Number of MyString<wchar_t>: " << ws.live() << std::endl;

	return 0;
}
