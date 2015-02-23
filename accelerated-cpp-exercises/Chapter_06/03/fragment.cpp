#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	std::vector<int> u(10,100);
	std::vector<int> v;
	//std::copy(u.begin(),u.end(),v.begin()); // segfaults
	std::copy(u.begin(),u.end(),std::back_inserter(v));

	std::cout << "Contents of v: " << std::endl;
	for(unsigned i=0;i<v.size();i++)
	{
		std::cout << v[i] << std::endl;
	}

	return 0;
}
