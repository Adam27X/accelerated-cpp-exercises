#pragma once

#include <stdexcept>

#include "ref_counter.hpp"

template <class T>
T* clone(const T* tp)
{
	return tp->clone();
}

template <class T>
class ptr
{
public:
	void make_unique()
	{
		if(refptr.val() != 1)
		{
			--refptr;
			refptr = ref_counter();
			p = p ? clone(p) : 0;
		}
	}

	ptr() : p(0) { }
	ptr(T* t) : p(t) { }
	
	ptr(const ptr &h) : p(h.p), refptr(h.refptr) { ++refptr; }
	ptr& operator=(const ptr &);
	~ptr();

	operator bool() const { return p; }

	T& operator*() const	
	{
		if(p)
		{
			return *p;
		}

		throw std::runtime_error("unbound ptr");
	}

	T* operator->() const
	{
		if(p)
		{
			return p;
		}

		throw std::runtime_error("unbound ptr");
	}

private:
	T* p;
	ref_counter refptr;
};

template <class T>
ptr<T>& ptr<T>::operator=(const ptr &rhs)
{
	++rhs.refptr;
	--refptr;
	// free the left hand side, destroying pointers if appropriate
	if(refptr.val() == 0)
	{
		delete p;
	}
	
	// copy in values from the right-hand side
	refptr = rhs.refptr;
	p = rhs.p;
	return *this;
}

template <class T>
ptr<T>::~ptr()
{
	--refptr;
	if(refptr.val() == 0)
	{
		delete p;
	}
}
