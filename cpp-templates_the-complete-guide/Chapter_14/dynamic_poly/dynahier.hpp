#include <iostream>
#include "coord.hpp"

//common abstract base class GeoObj for geometric objects
class GeoObj
{
public:
	//draw geometric object
	virtual void draw() const = 0;
	//return center of gravity of geometric object:
	virtual Coord center_of_gravity() const  = 0;
};

//concrete geometric object class Circle
//derived from GeoObj
class Circle : public GeoObj
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

class Line: public GeoObj
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
