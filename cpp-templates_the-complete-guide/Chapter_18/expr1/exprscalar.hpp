//class for objects that represent scalars
template <typename T>
class A_Scalar
{
private:
	T const &s; //value of the scalar

public:
	//constructor initializes value
	A_Scalar(T const &v) : s(v)
	{
		
	}

	//for index operations the scalar is the value of each element
	T operator[] (size_t) const
	{
		return s;
	}

	//scalars have zero as size
	size_t size() const
	{
		return 0;
	}
};
