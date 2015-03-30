#pragma once

#include "type1.hpp"
//#include "type2.hpp"
#include "type6.hpp"
#include "type3.hpp"
#include "type4.hpp"
#include "type5.hpp"
#include "type7.hpp"
#include "type8.hpp"

//define template that handles all in one style
template <typename T>
class TypeT
{
public:
	enum { IsFundaT = IsFundaT<T>::Yes, IsPtrT = CompoundT<T>::IsPtrT, IsRefT = CompoundT<T>::IsRefT, IsArrayT = CompoundT<T>::IsArrayT, IsFuncT = CompoundT<T>::IsFuncT, IsPtrMemT = CompoundT<T>::IsPtrMemT, IsEnumT = IsEnumT<T>::Yes, IsClassT = IsClassT<T>::Yes };
};
