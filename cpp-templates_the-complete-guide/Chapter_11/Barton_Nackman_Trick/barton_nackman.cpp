

class S
{

};

template <typename T>
class Wrapper
{
private:
	T object;
public:
	Wrapper(T obj) : object(obj) //Implicit conversion from T to Wrapper<T>
	{

	} 

	friend void f(Wrapper<T> const &a)
	{

	}
};

int main()
{
	S s;
	Wrapper<S> w(s);
	f(w); //OK: Wrapper<S> is a class associated with w
	//f(s); //ERROR: Wrapper<S> is not associated with S

	return 0;

}
