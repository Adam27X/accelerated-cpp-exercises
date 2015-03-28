#pragma once

#include "../ifthenelse.hpp"
#include "isclasst.hpp"

template <typename T>
class RParam
{
public:
	typedef typename IfThenElse<IsClassT<T>::No,
				    T,
				    T const&>::ResultT Type;
};
