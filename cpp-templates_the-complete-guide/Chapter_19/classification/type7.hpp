struct SizeOverOne { char c[2]; };

template <typename T,
	  bool convert_possible = !CompoundT<T>::IsFuncT && !CompoundT<T>::IsArrayT>
class ConsumeUDC
{
public:
	operator T() const;
};

//conversion to function types is not possible
template <typename T>
class ConsumeUDC<T,false>
{ };

//conversion to void type is not possible
template <bool convert_possible>
class ConsumeUDC<void,convert_possible>
{ };

char enum_check(bool);
char enum_check(char);
char enum_check(signed char);
char enum_check(unsigned char);
char enum_check(wchar_t);

char enum_check(signed short);
char enum_check(unsigned short);
char enum_check(signed int);
char enum_check(unsigned int);
char enum_check(signed long);
char enum_check(unsigned long);
char enum_check(signed long long);
char enum_check(unsigned long long);

//avoid accidental conversions from float to int
char enum_check(float);
char enum_check(double);
char enum_check(long double);

SizeOverOne enum_check(...); //catch all

template <typename T>
class IsEnumT
{
public:
	enum { Yes = IsFundaT<T>::No && !CompoundT<T>::IsRefT && !CompoundT<T>::IsPtrT && !CompoundT<T>::IsPtrMemT && sizeof(enum_check(ConsumeUDC<T>()))==1 };
	enum { No = !Yes };
};
