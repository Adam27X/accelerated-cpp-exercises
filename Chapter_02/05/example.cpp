#include <iostream>
#include <string>

int main()
{
	//Square
	std::string::size_type sq_size;
	std::cout << "Please enter the size of the square: ";
	std::cin >> sq_size;
	std::cout << std::endl;
	std::string top_bottom(sq_size,'*');
	std::string sq_padding(sq_size-2,' ');
	std::string middle = "*" + sq_padding + "*";

	std::cout << std::endl << top_bottom << std::endl;
	for(int i=0; i<sq_size-2; ++i)
	{
		std::cout << middle << std::endl;
	}
	std::cout << top_bottom << std::endl;

	//Rectangle
	std::cout << std::endl;
	std::string::size_type rec_width;
	std::string::size_type rec_height;
	std::cout << "Please enter the width of the rectangle: ";
	std::cin >> rec_width;
	std::cout << std::endl << "Please enter the height of the rectangle: ";
	std::cin >> rec_height;
	std::cout << std::endl;
	std::string top_bottom_rec(rec_width,'*');
	std::string rec_padding(rec_width-2,' ');
	middle = "*" + rec_padding + "*";

	std::cout << std::endl << top_bottom_rec << std::endl;
	for(int i=0; i<rec_height-2; ++i)
	{
		std::cout << middle << std::endl;
	}
	std::cout << top_bottom_rec << std::endl;

	//Triangle
	std::cout << std::endl;
	std::string::size_type tri_height;
	std::cout << "Please enter the height of the triangle (minimum 3): ";
	std::cin >> tri_height;
	std::cout << std::endl;
	const std::string::size_type tri_width = tri_height*2 - 1;
	for(int i=0; i<tri_height-1; ++i)
	{
		int midpoint = tri_width/2; //Index of the middle point
		if(i == 0)
		{
			for(int j=0; j<tri_width; ++j)
			{
				if(j == midpoint)
				{
					std::cout << "*";
				}
				else
				{
					std::cout << " ";
				}
			}
		}
		else
		{
			for(int j=0; j<tri_width; ++j)
			{
				if((j == midpoint+i) || (j == midpoint-i))
				{
					std::cout << "*";
				}
				else
				{
					std::cout << " ";
				}
			}
		}	
		std::cout << std::endl;
	}
	std::string final_row(tri_width,'*');
	std::cout << final_row << std::endl;

	return 0;
/*
  *
 * *
***** 

   *
  * *
 *   *     
*******     
*/
}
