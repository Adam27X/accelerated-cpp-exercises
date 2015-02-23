#pragma once

#include <stdexcept>

template <class T>
class handle
{
public:
	handle() : p(0) { }
	handle(const handle &h) : p(0) { if(h.p) { p = h.p->clone(); } }
	handle& operator=(const handle&);
	~handle() { delete p; }
	
	handle(T* t) : p(t) { }

	operator bool() const { return p; }
	T& operator*() const;
	T* operator->() const;

private:
	T* p;
};

template <class T>
handle<T>& handle<T>::operator=(const handle &rhs)
{
	if(&rhs != this)
	{
		delete p;
		p = rhs.p ? rhs.p->clone() : 0;
	}
	return *this;
}

template <class T>
T& handle<T>::operator*() const
{
	if(p)
	{
		return *p;
	}	
	else
	{
		throw std::runtime_error("unbound handle");
	}
}

template <class T>
T* handle<T>::operator->() const
{
	if(p)
	{
		return p;
	}
	else
	{
		throw std::runtime_error("unbound handle");
	}
}
