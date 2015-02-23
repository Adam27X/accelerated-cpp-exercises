#include <iostream>
#include <string>

class node
{
public:
	node();
	node(const char *s);
	node(const std::string s);
	std::string get_data() const { return data; }
	std::string operator*() { return data; }
	node operator++() { node tmp = *(this->next); *this = tmp; return *this; }
	node operator--() { node tmp = *(this->prev); *this = tmp; return *this; }
	bool operator==(const node &rhs) { return data == rhs.data; }
	bool operator!=(const node &rhs) { return data != rhs.data; }
	node *next;
	node *prev;

private:
	std::string data;
};

node::node() : prev(NULL), next(NULL), data(" ") { }
node::node(const std::string s) : prev(NULL), next(NULL), data(s) { }

class string_list
{
public:
	string_list();
	string_list(const std::string s);
	template <class Iterator>
	string_list(Iterator b, Iterator e);
	
	size_t size() const { return links; }
	void push_back(std::string s);
	bool empty() const { return links==0; }
	std::string front() const { return head->get_data(); }
	std::string back() const { return tail->get_data(); }
	void print_forward() const; 
	void print_backward() const;
	node begin() const { return *head; }
	node end() const { return *tail; }

private:
	node *head; //Beginning of the list
	node *tail; //End of the list
	int links;
};

string_list::string_list() : links(0) {}

string_list::string_list(const std::string s) : links(1)
{
	head = new node(s);
	tail = head->next;
}

template <class Iterator>
string_list::string_list(Iterator b, Iterator e)
{
	if(b == e)
	{
		string_list();
	}
	head = new node(*b);
	links++;
	b++;
	node *trav = head;
	while(b != e)
	{
		trav->next = new node(*b);
		links++;
		b++;
		trav->next->prev = trav;
		trav = trav->next;
	}
	tail = trav;	
}

void string_list::push_back(std::string s)
{
	node *trav = tail;
	trav->next = new node(s);
	trav->next->prev = trav;
	tail = trav->next;
}

void string_list::print_forward() const
{
	node *trav = head;
	while(trav != NULL)
	{
		std::cout << trav->get_data() << std::endl;
		trav = trav->next;
	}
}

void string_list::print_backward() const
{
	node *trav = tail;
	while(trav != NULL)
	{
		std::cout << trav->get_data() << std::endl;
		trav = trav->prev;
	}
}
