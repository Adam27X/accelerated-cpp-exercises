#include <iostream>

template <int N>   
class X {   
  public:   
    typedef int I;   
    void f(int) {   
    }   
};   
   
template<int N>    
void fppm(void (X<N>::*p)(typename X<N>::I))
{
	std::cout << "Parameter of fppm function analyzed participating in type deduction in nondeduced context!" << std::endl;
} 
   
int main()    
{   
    fppm(&X<33>::f);  // fine: N deduced to be 33   
}   
