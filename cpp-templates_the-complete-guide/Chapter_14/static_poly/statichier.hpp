#include <iostream>
#include "coord.hpp"

//concrete geometric object class Circle
// NOT derived from any class
class Circle
{
public:
	virtual void draw() const
	{
		std::cout << "Drew a circle." << std::endl;
	}

	virtual Coord center_of_gravity() const
	{
		std::cout << "COG called for a circle." << std::endl;
		return Coord(0,0);
	}
};

class Line
{
public:
	virtual void draw() const
	{
		std::cout << "Drew a line." << std::endl;
	}

	virtual Coord center_of_gravity() const
	{
		std::cout << "COG called for a line." << std::endl;
		return Coord(1,1);
	}
};
