#pragma once

//primary template: yield second or third argument depending on first argument
template<bool C, typename Ta, typename Tb>
class IfThenElse;

//partial specialization: true yields second argument
template<typename Ta, typename Tb>
class IfThenElse<true,Ta,Tb>
{
public:
	typedef Ta ResultT;
};

template<typename Ta, typename Tb>
class IfThenElse<false,Ta,Tb>
{
public:
	typedef Tb ResultT;
};
