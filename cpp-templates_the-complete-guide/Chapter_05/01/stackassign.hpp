template <typename T>
template <typename T2>
Stack<T>& Stack<T>::operator=(Stack<T2> const &op2)
{
	//Check for self-assignment
	if((void*)this == (void*)&op2)
	{
		return *this;
	}

	Stack<T2> tmp(op2);

	elems.clear();
	while(!tmp.empty())
	{
		elems.push_front(tmp.top());
		tmp.pop();
	}

	return *this;
}
