#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	std::vector<int> u(10,100);
	std::vector<int> v(u.size()); //second way: advantage: preallocate the size of u for best performance. disadvantage: need to know the size of u a priori
	std::copy(u.begin(),u.end(),v.begin()); 

	//std::copy(u.begin(),u.end(),std::back_inserter(v)); //first way: advantage: don't need to know the size of u. disadvantage: may resize u multiple times, could be slow

	std::cout << "Contents of v: " << std::endl;
	for(unsigned i=0;i<v.size();i++)
	{
		std::cout << v[i] << std::endl;
	}

	return 0;
}
