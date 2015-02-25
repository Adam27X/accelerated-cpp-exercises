#include <deque>
#include <stdexcept>

template <typename T, typename CONT = std::deque<T> >
class Stack
{
private:
	CONT elems;

public:
	void push(T const &);
	void pop();
	T top() const;
	bool empty() const
	{
		return elems.empty();
	}

	template <typename T2, typename CONT2>
	Stack<T,CONT>& operator=(Stack<T2,CONT2> const&);
};

template <typename T, typename CONT>
void Stack<T,CONT>::push(T const& elem)
{
        elems.push_back(elem); //append copy of passed elem
}

template <typename T, typename CONT>
void Stack<T,CONT>::pop()
{
        if(elems.empty())
        {
                throw std::out_of_range("Stack<>::pop(): empty stack");
        }

        return elems.pop_back(); //remove last element
}

template <typename T, typename CONT>
T Stack<T,CONT>::top() const
{
        if(elems.empty())
        {
                throw std::out_of_range("Stack::top(): empty stack");
        }

        return elems.back(); //return copy of last element
}
