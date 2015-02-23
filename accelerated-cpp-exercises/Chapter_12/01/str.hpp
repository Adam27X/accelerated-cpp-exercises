//Could easily specialize vec to solve this problem, but the problem statement suggests the 
// more tedious approach of using char*/size variables
//Rather than recreate what vec does in terms of allocation, we'll try using new/delete
#pragma once

#include <iostream>
#include <cstring>
#include <cstddef>

class str
{
	friend std::istream& operator>>(std::istream &, str &);

public:	
	typedef size_t size_type;
        typedef char* iterator;
        typedef const char* const_iterator;

	str() : s(NULL), len(0) { } 

	str& operator+=(const str &rhs)
	{
		size_type rhs_len = rhs.size();
		size_type orig_len = this->size();
		//Again, using an ugly buffer for simplicity
		const size_t buffer_size = 200;
		char buffer[buffer_size];
		for(size_type i=0; i<orig_len; i++)
		{
			buffer[i] = s[i];
		}

		destroy();
		len = rhs_len + orig_len + 1;
		s = new char[len];
		for(size_type i=0; i<orig_len; i++)
		{
			s[i] = buffer[i];
		}
		for(size_type i=0; i<rhs_len; i++)
		{
			s[i+orig_len] = rhs[i];
		}
		s[len-1] = '\0';
		return *this;
	}
	
	//Initialize a string of length n, which each character equivalent to c
	str(size_type n, const char &c) 
	{
		create(n,c);
	}

	str(const char* cp)
	{
		create(cp);
	}

	template <class InputIterator>
	str(InputIterator b, InputIterator e)
	{
		destroy();
		create(b,e);
	}

	str(const str& t)
	{
		create(t);
	}

	str& operator=(const str& rhs)
	{
		if(&rhs != this)
		{
			destroy();
		
			create(rhs);	
		}
	}

	~str() { destroy(); }

	char& operator[](size_type i) { return s[i]; }
	const char& operator[](size_type i) const { return s[i]; }
	size_type size() const { return len-1; } 
	void clear() { destroy(); }
	bool valid() { return s != NULL; }

        iterator begin() { return &s[0]; }
        const_iterator begin() const { return &s[0]; }
        iterator end() { return &s[len]; }
        const_iterator end() const { return &s[len]; }

private:
	char *s;
	size_type len; // size of string + 1 for null terminating character. Abstract the null terminator from the user, though.

	void create(size_type n, const char &c);
	void create(const char *cp);
	template <class InputIterator>
	void create(InputIterator b, InputIterator e);
	void create(const str &rhs);
	void destroy();
};

std::ostream& operator<<(std::ostream &os, str &s)
{
	for(str::size_type i=0; i<s.size(); i++)
	{
		os << s[i];
	}

	return os;
}

std::istream& operator>>(std::istream &is, str &s)
{
	if(s.size() != 0)
	{
		s.clear();
	}

	//no push_back -> use a temp buffer
	// for simplicity I'll just refuse to take more than buffer_size characters
	// in reality we could dump and refill the buffer but that's not worth the effort right now
	const int buffer_size = 20;
	char buffer[buffer_size];
	size_t buffer_id = 0;	
	
	char c;
	while(is.get(c) && isspace(c)) { }

	if(is)
	{
		do
		{
			buffer[buffer_id] = c;
			buffer_id++;
		}
		while(is.get(c) && !isspace(c) && buffer_id<buffer_size);
	
		if(is)
		{
			is.unget();
		}

		s.s = new char[buffer_id+1];
		s.len = buffer_id+1;
		for(size_t i=0; i<buffer_id; i++)
		{
			s[i] = buffer[i]; //could also do s.s[i] = ...
		}
		s[buffer_id] = '\0';	
	}

	return is;
}

void str::destroy()
{
	if(s)
	{
		delete[] s;
		len = 0;
		s = NULL;
	}
}

void str::create(size_type n, const char &c)
{
	s = new char[n+1];
	for(size_type i=0; i<n; i++)
	{
		s[i] = c;
	}
	s[n] = '\0';
	len = n+1;
}

void str::create(const char *cp)
{
	size_type cplen = std::strlen(cp); //len will NOT include the null terminator
	s = new char[cplen+1];
	for(size_type i=0; i<cplen; i++)
	{
		s[i] = cp[i];
	}
	s[cplen] = '\0';
	len = cplen+1;
}

template <class InputIterator>
void str::create(InputIterator b, InputIterator e)
{
	std::ptrdiff_t n = e-b;
	s =  new char[n+1];
	std::copy(b,e,s);
	s[n] = '\0';
	len = n+1;
}

void str::create(const str &rhs)
{
	size_type tlen = rhs.size();
	s = new char[tlen+1];
	for(size_type i=0; i<tlen; i++)
	{
		s[i] = rhs[i];
	}
	s[tlen] = '\0';
	len = tlen+1;
}

str operator+(const str &s, const str &t)
{
	str r = s;
	r += t;
	return r;
}
