#include <iostream>

//Only SrcT can be deduced
//Hence, put DstT as the first param so that it isn't always necessary to include both template arguments explicitly
template <typename DstT, typename SrcT> 
inline DstT implicit_cast(const SrcT &x)
{
	return x;
}

int main()
{	
	std::cout << "implicit_cast<double>(-1): " << implicit_cast<double>(-1) << std::endl;

	return 0;
}
