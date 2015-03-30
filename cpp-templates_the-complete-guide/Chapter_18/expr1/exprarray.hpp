#include <stddef.h>
#include <cassert>
#include "sarray1.hpp"

template <typename T, typename Rep = SArray<T> >
class Array
{
private:
	Rep expr_rep; //(acces to) the data of the array

public:
	//create array with initial size
	explicit Array(size_t s) : expr_rep(s)
	{
		
	}

	//create array from possible representation
	Array(Rep const &rb) : expr_rep(rb)
	{
		
	}

	//assignment operator for same type
	Array& operator=(Array const &b)
	{
		assert(size() == b.size());
		for(size_t idx=0; idx<b.size(); ++idx)
		{
			expr_rep[idx] = b[idx];
		}

		return *this;
	}

	//Assignment operator for arrays of different type
	template <typename T2, typename Rep2>
	Array& operator=(Array<T2,Rep2> const &b)
	{
		assert(size() == b.size());
		for(size_t idx=0; idx<b.size(); ++idx)
		{
			expr_rep[idx] = b[idx];
		}
		return *this;
	}

	//size is size of represented data
	size_t size() const 
	{
		return expr_rep.size();
	}

	//index operator for constants and variables
	T operator[](size_t idx) const
	{
		assert(idx<size());
		return expr_rep[idx];
	}
	T& operator[](size_t idx)
	{
		assert(idx<size());
		return expr_rep[idx];
	}

	//return what the array currently represents
	Rep const& rep() const
	{
		return expr_rep;
	}
	Rep& rep()
	{
		return expr_rep;
	}
};
