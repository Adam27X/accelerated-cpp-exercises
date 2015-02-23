#pragma once

#include <cstddef>

class ref_counter
{
public:
	ref_counter() : refptr(new std::size_t(1)) { }
	std::size_t val() const { return *refptr; }
	
	void operator++() const { ++*refptr; }
	void operator--() const { if(--*refptr == 0) delete refptr; }

private:
	std::size_t* refptr;
};
