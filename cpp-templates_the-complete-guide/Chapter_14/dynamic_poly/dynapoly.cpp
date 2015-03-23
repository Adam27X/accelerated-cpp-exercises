#include <vector>
#include "dynahier.hpp"

//draw any GeoObj
void myDraw(GeoObj const &obj)
{
	obj.draw(); //call draw() according to the type of object
}

//process distance of center of gravity between two GeoObjs
Coord distance(GeoObj const &x1, GeoObj const &x2)
{
	Coord c = x1.center_of_gravity() - x2.center_of_gravity();
	return c.abs(); //return coordinates as absolute values
}

//draw heterogeneous collection of GeoObjs
void drawElems(std::vector<GeoObj*> const &elems)
{
	for(unsigned i=0; i<elems.size(); ++i)
	{
		elems[i]->draw(); //call draw() according to type of element
	}
}

int main()
{
	Line l;
	Circle c, c1, c2;

	myDraw(l);
	myDraw(c);

	distance(c1,c2);
	distance(l,c);

	std::vector<GeoObj*> coll;
	coll.push_back(&l);
	coll.push_back(&c);
	drawElems(coll);

	return 0;
}
