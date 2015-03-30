template <typename T>
class CompoundT //primary template
{
public:
	enum { IsPtrT = 0, IsRefT = 0, IsArrayT = 0, IsFuncT = 0, IsPtrMemT = 0 };
	typedef T BaseT;
	typedef T BottomT;
	typedef CompoundT<void> ClassT;
};
