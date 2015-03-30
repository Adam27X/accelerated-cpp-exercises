#pragma once 

//primary template
template <typename T>
class A_Traits
{
public:
	typedef T const& ExprRef; //type to refer to is constant reference
};

//partial specialization for scalars
template <typename T>
class A_Traits<A_Scalar<T> > 
{
public:
	typedef A_Scalar<T> ExprRef; //type to refer to is ordinary value
};
