#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <climits>
#include <cmath>

const int RAND_MAX_TEST = 32767;

// return a random integer in the range [0,n)
int nrand(int n)
{
        if(n <= 0)
        {
                throw std::domain_error("Argument to nrand is out of range");
        }

        int r;

	if(n <= RAND_MAX_TEST)
	{
		const int bucket_size = RAND_MAX_TEST/n;
		do
		{
			r = rand() / bucket_size;
		} while(r >= n);
	}
	else
	{
		const int bucket_size = ceil(n/RAND_MAX_TEST); //Up to RAND_MAX buckets
		
		do
		{
			const int bucket = nrand(RAND_MAX_TEST); //Choose a bucket
			const int remainder = nrand(bucket_size); //Choose a bucket element
			r = (bucket-1)*bucket_size + remainder; //Reconstruct number
		} while(r >= n);
	}

        return r;
}

int main()
{
	for(unsigned i=0; i<20; i++)
	{
		std::cout << "nrand(4000000): " << nrand(4000000) << std::endl;
	}

	return 0;
}
