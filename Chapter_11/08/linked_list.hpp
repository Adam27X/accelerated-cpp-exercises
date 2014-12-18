#pragma once

#include <memory>
#include <cstddef>

template <class T> 
class linked_list
{
public:
        typedef T* iterator;
        typedef const T* const_iterator;
        typedef size_t size_type;
        typedef T value_type;
	typedef std::ptrdiff_t difference_type;
        typedef T& reference;
        typedef const T& const_reference;

	linked_list() { resize(0); }
	linked_list(const linked_list &l) { clone(l.data,l.avail); } //copy constructor
	linked_list(const_iterator b, const_iterator e) { clone(b,e); }
	linked_list& operator=(const linked_list&); //assignment operator
	~linked_list() { destroy(); } //destructor
	
	size_type size() const { return avail-data; }

	void clear() { destroy(); }

	bool empty() const { return data==avail; } 

	iterator begin() { return data; }
	const_iterator begin() const { return data; }
	iterator end() { return avail; }
	const_iterator end() const { return avail; }

private:
	iterator data;
	iterator avail;
	std::allocator<T> alloc;

	void clone(const_iterator b, const_iterator e);
	void destroy();
	void resize(size_type size);	
};

template <class T>
linked_list<T>& linked_list<T>::operator=(const linked_list &rhs)
{
	if(&rhs != this)
	{
		destroy();
		clone(rhs.data,rhs.avail);
	}

	return *this;
}

template <class T>
void linked_list<T>::destroy()
{
	if(data)
	{
		for(iterator it=data; it!=avail; ++it)
		{
			alloc.destroy(it);
		}

		alloc.deallocate(data,avail-data);
	}

	data = avail = 0;
}

template <class T>
void linked_list<T>::clone(const_iterator b, const_iterator e)
{
	resize(e-b);
	std::uninitialized_copy(b,e,data);
}

template <class T>
void linked_list<T>::resize(size_type size)
{
	data = alloc.allocate(size);
	avail = data+size;
}
