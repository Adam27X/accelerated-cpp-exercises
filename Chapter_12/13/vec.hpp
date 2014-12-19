#pragma once

#include <algorithm> // max
#include <memory> // allocator class
#include <cstddef> // ptrdiff_t

template <class T> class vec
{
public:
	typedef T* iterator;
	typedef const T* const_iterator;
	typedef size_t size_type;
	typedef T value_type;
	typedef T& reference;
	typedef const T& const_reference;

	vec() { create(); }
	explicit vec(size_type n, const T& t = T()) { create(n,t); }
	template <class InputIterator>
	vec(InputIterator b, InputIterator e)
	{
		create(b,e);
	}

	vec(const vec &v) { create(v.begin(),v.end()); }
	vec& operator=(const vec&);
	~vec() { uncreate(); }

	T& operator[](size_type i) { return data[i]; }
	const T& operator[](size_type i) const { return data[i]; }
	
	void push_back(const T &t)
	{
		if(avail == limit)
		{
			grow();
		}
		unchecked_append(t);
	}

	size_type size() const { return avail - data; }

	iterator erase(iterator position)
	{
		for(iterator i=position; i!=avail; ++i)
		{
			alloc.destroy(i);
			if((i+1) != avail)
			{
				alloc.construct(i,*(i+1));
			}
		}

		--avail;

		return position;
	}

	void clear();

	bool empty() const { return data == avail; }

	template <class InputIterator>
	void insert(iterator position, InputIterator first, InputIterator last)
	{
		size_type new_size = (avail-data) + (last-first);
		iterator new_data = alloc.allocate(new_size);
		std::uninitialized_copy(data,position,new_data);
		std::uninitialized_copy(first,last,new_data+(position-data));
		iterator new_avail = std::uninitialized_copy(position,avail,new_data + (position - data)  + (last-first));

		uncreate();

		data = new_data;
		avail = new_avail;
		limit = data + new_size;
	}

	template <class InputIterator>
	void assign(InputIterator first, InputIterator last)
	{
		uncreate();
		create(first,last);
	}
	
	iterator begin() { return data; }
	const_iterator begin() const { return data; }
	iterator end() { return avail; }
	const_iterator end() const { return avail; }

private:
	iterator data; // first element in the vec
	iterator avail; // (one past) the last element in the vec
	iterator limit; // (one paste) the allocated memory

	// facilities for memory allocation
	std::allocator<T> alloc; // object to handle memory allocation

	// allocate and initialize the underlying array
	void create();
	void create(size_type n, const T& v);
	template <class InputIterator>
	void create(InputIterator b, InputIterator e);

	// destroy the elements in the array and free the memory 
	void uncreate();

	// support functions for push_back
	void grow();
	void unchecked_append(const T& v);
};

template <class T>
vec<T>& vec<T>::operator=(const vec & rhs)
{
	// check for self-assignment
	if(&rhs != this)
	{
		// free the array in the left-hand side
		uncreate();

		// copy elements from the right-hand to the left-hand side
		create(rhs.begin(),rhs.end());
	}

	return *this;
}

template <class T>
void vec<T>::create()
{
	data = avail = limit = 0;
}

template <class T>
void vec<T>::create(size_type n, const T& v)
{
	data = alloc.allocate(n);
	limit = avail = data + n;
	std::uninitialized_fill(data,limit,v);
}

template <class T>
template <class InputIterator>
void vec<T>::create(InputIterator b, InputIterator e)
{
	data = alloc.allocate(e-b);
	limit = avail = std::uninitialized_copy(b,e,data);
}

template <class T>
void vec<T>::uncreate()
{
	if(data)
	{
		// destroy (in reverse order) the elements that were constructed
		iterator it = avail;
		while(it != data)
		{
			alloc.destroy(--it);
		}

		// return all the space that was allocated
		alloc.deallocate(data,limit-data);
	}

	// reset pointers to indicate that the vec is empty again
	data = avail = limit = 0;
}

template <class T>
void vec<T>::grow()
{
	// when growing, allocate twice as much space as currently in use
	size_type new_size = std::max(2*(limit-data),std::ptrdiff_t(1));

	// allocate new space and copy existing elements to the new space
	iterator new_data = alloc.allocate(new_size);
	iterator new_avail = std::uninitialized_copy(data,avail,new_data);

	// return the old space
	uncreate();

	// reset pointers to point to the newly allocated space
	data = new_data;
	avail = new_avail;
	limit = data + new_size;
}

// assumes avail points at allocated, but uninitialized space
template <class T>
void vec<T>::unchecked_append(const T& v)
{
	alloc.construct(avail++,v);
}


template <class T>
void vec<T>::clear()
{
	uncreate(); // start from scratch
}
