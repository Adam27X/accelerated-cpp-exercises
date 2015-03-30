#include <stddef.h>
#include <cassert>

template <typename T>
class SArray
{
public:
	//create array with initial size
	explicit SArray(size_t s) : storage(new T[s]), storage_size(s)
	{
		init();
	}

	//copy constructor
	SArray(SArray<T> const &orig) : storage(new T[orig.size()]), storage_size(orig.size())
	{
		copy(orig);
	}

	//destructor
	~SArray()
	{
		delete[] storage;
	}

	//assignment operator
	SArray<T>& operator=(SArray<T> const &orig)
	{
		if(&orig!=this)
		{
			copy(orig);
		}
		return *this;
	}

	//return size
	size_t size() const
	{
		return storage_size;
	}

	//index operator for constants and variables
	T operator[] (size_t idx) const
	{
		return storage[idx];
	}

	T& operator[] (size_t idx)
	{
		return storage[idx];
	}

	SArray<T>& operator+=(SArray<T> const &b);
	SArray<T>& operator*=(SArray<T> const &b);
	SArray<T>& operator*=(T const &s);

protected:
	//init values with default constructor
	void init()
	{
		for(size_t idx=0; idx<size(); ++idx)
		{
			storage[idx] = T();
		}
	}

	//copy values of another array
	void copy(SArray<T> const &orig)
	{
		assert(size()==orig.size());
		for(size_t idx=0; idx<size(); ++idx)
		{
			storage[idx] = orig.storage[idx];
		}
	}

private:
	T* storage;
	size_t storage_size;
};
