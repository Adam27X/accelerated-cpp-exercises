#pragma once

#include <stdexcept>

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
		if(*refptr != 1)
		{
			--*refptr;
			refptr = new std::size_t(1);
			p = p ? clone(p) : 0;
		}
	}

	ptr() : p(0), refptr(new std::size_t(1)) { }
	ptr(T* t) : p(t), refptr(new std::size_t(1)) { }
	
	ptr(const ptr &h) : p(h.p), refptr(h.refptr) { ++*refptr; }
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
	std::size_t* refptr;
};

template <class T>
ptr<T>& ptr<T>::operator=(const ptr &rhs)
{
	++*rhs.refptr;
	// free the left hand side, destroying pointers if appropriate
	if(--*refptr == 0)
	{
		delete refptr;
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
	if(--*refptr == 0)
	{
		delete refptr;
		delete p;
	}
}
