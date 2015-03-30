#include <stddef.h>
#include <cassert>

#include "exprops1a.hpp"

//class for objects that represent the addition of two operands
template <typename T, typename OP1, typename OP2>
class A_Add
{
private:
	typename A_Traits<OP1>::ExprRef op1; //first operand
	typename A_Traits<OP2>::ExprRef op2; //second operand

public:
	//constructor initializes references to operands
	A_Add(OP1 const &a, OP2 const &b) : op1(a), op2(b)
	{

	}

	//compute sum when value requested
	T operator[] (size_t idx) const
	{
		return op1[idx] + op2[idx];
	}	

	//size is maximum size
	size_t size() const
	{
		assert(op1.size()==0 || op2.size()==0 || op1.size()==op2.size());
		return op1.size()!=0 ? op1.size() : op2.size();
	}
};

//class for objects that represent the multiplication of two operands
template <typename T, typename OP1, typename OP2>
class A_Mult
{
private:
	typename A_Traits<OP1>::ExprRef op1; //first operand
	typename A_Traits<OP2>::ExprRef op2; //second operand

public:
	//constructor initializes references to operands
	A_Mult(OP1 const &a, OP2 const &b) : op1(a), op2(b)
	{

	}

	//compute sum when value requested
	T operator[] (size_t idx) const
	{
		return op1[idx] * op2[idx];
	}	

	//size is maximum size
	size_t size() const
	{
		assert(op1.size()==0 || op2.size()==0 || op1.size()==op2.size());
		return op1.size()!=0 ? op1.size() : op2.size();
	}
};
