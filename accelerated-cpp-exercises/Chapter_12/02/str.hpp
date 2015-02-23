#pragma once

#include <iostream>
#include <algorithm>
#include <cctype>
#include <cstring>

#include "vec.hpp"

class str
{
	friend std::istream& operator>>(std::istream&, str&);

public:
        typedef char* iterator;
        typedef const char* const_iterator;

	str& operator+=(const str& s)
	{
		std::copy(s.data.begin(), s.data.end(), std::back_inserter(data));
		return *this;
	}

	typedef vec<char>::size_type size_type;

	str() { }
	str(size_type n, char c) : data(n,c) { }
	str(const char *cp) 
	{
		std::copy(cp,cp+std::strlen(cp),std::back_inserter(data));
	}
	template <class InputIterator>
	str(InputIterator b, InputIterator e)
	{
		std::copy(b,e,std::back_inserter(data));
	}

	char& operator[](size_type i) { return data[i]; }
	const char& operator[](size_type i) const { return data[i]; }
	size_type size() const { return data.size(); }

        iterator begin() { return data.begin(); }
        const_iterator begin() const { return data.begin(); }
        iterator end() { return data.end(); }
        const_iterator end() const { return data.end(); }

	//Technically c_str() should return a null-terminated string and data shouldn't, but we don't null terminate so we'll treat both the same for simplicity
	const char* c_str()
	{
		return begin();
	}

	//renamed because data() conflicts with the name of our vec. It would be better to simply rename the vec, but I'm lazy.
	const char* get_data()
	{
		return begin();
	}

	size_type copy(char *s, size_type n, size_type pos=0)
	{
		size_type copied = 0;
		for(size_type i=pos; i<n; i++)
		{
			if(i > size())
			{
				break;
			}
			s[i-pos] = data[i];
			copied++;
		}

		return copied;
	}	


private:
	vec<char> data;
};

std::ostream& operator<<(std::ostream &os, str &s)
{
	for(str::size_type i=0; i!=s.size(); i++)
	{
		os << s[i];
	}

	return os;
}

std::istream& operator>>(std::istream &is, str &s)
{
	// obliterate existing value(s)
	s.data.clear();

	// read and discard leading whitespace
	char c;
	// nothing to do except test the conditions
	while(is.get(c) && isspace(c))	{ }
	
	// if there is still something to read, do so until the next whitespace character
	if(is)
	{
		do
		{
			s.data.push_back(c);
		}
		while(is.get(c) && !isspace(c));

		// if we read whitespace, then put it back on the stream
		if(is)
		{
			is.unget();
		}
	}

	return is;
}

str operator+(const str &s, const str &t)
{
	str r = s;
	r += t;
	return r;
}
