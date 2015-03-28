template <typename T>
class TypeOp
{
public:
	typedef T ArgT;
	typedef T BareT;
	typedef T const ConstT;
	typedef T & RefT;
	typedef T & RefBareT;
	typedef T const & RefConstT;
};

template <typename T>
class TypeOp <T const> //partial specialization for const types
{
public:
	typedef T const ArgT;
	typedef T BareT;
	typedef T const ConstT;
	typedef T const & RefT;
	typedef T & RefBareT;
	typedef T const & RefConstT;
};

template <typename T>
class TypeOp <T&> //partial specialization for references
{
public:
	typedef T & ArgT;
	typedef typename TypeOp<T>::BareT BareT;
	typedef T const ConstT;
	typedef T & RefT;
	typedef typename TypeOp<T>::BareT & RefBareT;
	typedef T const & RefConstT;
};

template<>
class TypeOp<void> //full specialization for void
{
public:
	typedef void ArgT;
	typedef void BareT;
	typedef void ConstT;
	typedef void RefT;
	typedef void RefBareT;
	typedef void RefConstT;
};

template <typename T>
void apply(typename TypeOp<T>::RefT arg, void (*func)(T))
{
	func(arg);
}
