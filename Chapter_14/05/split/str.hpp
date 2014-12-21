#pragma once

#include <iostream>
#include <algorithm>
#include <cctype>
#include <cstring>
#include <iterator>

#include "vec.hpp"
#include "ptr.hpp"

template<>
vec<char>* clone(const vec<char>* vp)
{
	return new vec<char>(*vp);
}

class str
{
	friend std::istream& operator>>(std::istream&, str&);
	friend std::istream& getline(std::istream &is, str &s);

public:
        typedef char* iterator;
        typedef const char* const_iterator;
	typedef size_t size_type;

	str& operator+=(const str& s)
	{
		data.make_unique();
		std::copy(s.data->begin(), s.data->end(), std::back_inserter(*data));
		return *this;
	}

	str& operator+=(const char* &s)
	{
		data.make_unique();
		size_type len = std::strlen(s);
		std::copy(s,s+len,std::back_inserter(*data));
	}

	str() : data(new vec<char>) { }
	str(size_type n, char c) : data(new vec<char>(n,c)) { }

	str(const char *cp) : data(new vec<char>)
	{
		std::copy(cp,cp+std::strlen(cp),std::back_inserter(*data));
	}

	template <class InputIterator>
	str(InputIterator b, InputIterator e) : data(new vec<char>)
	{
		std::copy(b,e,std::back_inserter(*data));
	}

	char& operator[](size_type i) 
	{
		data.make_unique(); 
		return (*data)[i]; 
	}

	const char& operator[](size_type i) const 
	{ 
		return (*data)[i]; 
	}

	size_type size() const { return data->size(); }

        iterator begin() { return data->begin(); }
        const_iterator begin() const { return data->begin(); }
        iterator end() { return data->end(); }
        const_iterator end() const { return data->end(); }

	operator bool() const { return size() > 0; }

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
			s[i-pos] = (*data)[i];
			copied++;
		}

		return copied;
	}	

	str substr(size_type pos, size_type len) const
	{
		str ret(begin()+pos,begin()+pos+len);
		return ret;
	}

	template <class InputIterator>
	void insert(iterator position, InputIterator b, InputIterator e)
	{
		data->insert(position,b,e);
	}


private:
	ptr< vec<char> > data;
};

std::ostream_iterator<char>& operator<<(std::ostream_iterator<char> &os, str &s)
{
	std::copy(s.begin(),s.end(),os);
	return os;
}

std::ostream& operator<<(std::ostream &os, str &s)
{
	for(str::size_type i=0; i!=s.size(); i++)
	{
		os << s[i];
	}

	return os;
}

std::ostream& operator<<(std::ostream &os, const str &s)
{
	for(str::size_type i=0; i!=s.size(); i++)
	{
		os << s[i];
	}
	
	return os;
}

std::istream& getline(std::istream &is, str &s)
{
	//s.data->clear();
	s.data = new vec<char>;
	
	char c;
	while(is.get(c))
	{
		if(c != '\n')
		{
			s.data->push_back(c);
		}
		else
		{
			break;
		}
	}
	
	return is;
}

std::istream& operator>>(std::istream &is, str &s)
{
	// obliterate existing value(s)
	s.data->clear();

	// read and discard leading whitespace
	char c;
	// nothing to do except test the conditions
	while(is.get(c) && isspace(c))	{ }
	
	// if there is still something to read, do so until the next whitespace character
	if(is)
	{
		do
		{
			s.data->push_back(c);
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

str operator+(const str &s, const char* &t)
{
	str r = s;
	r += t;
	return r;
}

str operator+(const char* &s, const str &t)
{
	str r(s);
	r += t;
	return r;
}

bool operator<(str &s, str &t)
{
	return std::lexicographical_compare(s.begin(),s.end(),t.begin(),t.end());
}

bool operator<=(str &s, str &t)
{
	return !std::lexicographical_compare(t.begin(),t.end(),s.begin(),s.end());
}

bool operator>(str &s, str &t)
{
	return std::lexicographical_compare(t.begin(),t.end(),s.begin(),s.end());
}

bool operator>=(str &s, str &t)
{
	return !std::lexicographical_compare(s.begin(),s.end(),t.begin(),t.end());
}

// a slightly cleaner approach would be to use std::equal after checking sizes
bool operator==(str &s, str &t)
{
	if(s.size() != t.size())
	{
		return false;
	}

	str::size_type size = s.size();
	for(str::size_type i=0; i<size; i++)
	{
		if(s[i] != t[i])
		{
			return false;
		}
	}

	return true;
}

bool operator!=(str &s, str &t)
{
	return !(s==t);
}
