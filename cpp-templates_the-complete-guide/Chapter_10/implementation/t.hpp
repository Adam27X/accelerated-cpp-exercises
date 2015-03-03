//common header (inclusion model)
template <typename T>
class S
{
public:
	void f();
};

template <typename T>
void S<T>::f() //member definition
{

}

void helper(S<int>*);
