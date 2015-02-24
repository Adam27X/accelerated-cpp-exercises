#include <iostream>
#include <deque>
#include <string>
#include <stdexcept>

#include "stack.hpp"

template<>
class Stack<std::string> 
{
private:
	std::deque<std::string> elems; //elements

public:
	void push(std::string const &);
	void pop();
	std::string top() const;
	bool empty() const
	{
		return elems.empty();
	}
};

void Stack<std::string>::push(std::string const &elem)
{
	elems.push_back(elem);
}

void Stack<std::string>::pop()
{
	if(elems.empty())
	{
		throw std::out_of_range("Stack<std::string>::pop(): empty stack");
	}	

	elems.pop_back();
}

std::string Stack<std::string>::top() const
{
	if(elems.empty())
	{
		throw std::out_of_range("Stack<std::string>::top(): empty stack");
	}

	return elems.back();
}	

int main()
{
        try
        {
                Stack<int> intStack;
                Stack<std::string> stringStack;

                intStack.push(7);
                std::cout << "intStack.top(): " << intStack.top() << std::endl;

                stringStack.push("hello");
                std::cout << "stringStack.top(): " << stringStack.top() << std::endl;
                stringStack.pop();

                stringStack.pop(); //error
        }
        catch(std::exception const &e)
        {
                std::cerr << "Caught exception: " << e.what() << std::endl;
        }

        return 0;
}
