#include <stddef.h>

template <typename CountedType>
class ObjectCounter
{
private:
	static size_t count; //number of existing objects

protected:
	//default constructor
	ObjectCounter()
	{
		++ObjectCounter<CountedType>::count;
	}

	//copy constructor
	ObjectCounter(ObjectCounter<CountedType> const &)
	{
		++ObjectCounter<CountedType>::count;
	}

	//destructor
	~ObjectCounter()
	{
		--ObjectCounter<CountedType>::count;
	}

public:
	static size_t live()
	{
		return ObjectCounter<CountedType>::count;
	}
};

//initialize counter with zero
template <typename CountedType>
size_t ObjectCounter<CountedType>::count = 0;
