#include "ch.h"

//constructor sets values for number of points, the maxs and mins
Convex::Convex(int np, int mxX, int mxY, int mnX, int mnY)
{
	numPoints = np;
	maxX = mxX;
	maxY = mxY;
	minX = mnX;
	minY = mnY;
}

//creates a bunch of random points
void Convex::generatePoints()
{
	for (int i = 0; i < numPoints; i++) {
		point temp;
		temp.x = rand() % (maxX - minX + 1) + minX;
		temp.y = rand() % (maxY - minY + 1) + minY;
		points.push_back(temp);
	}
}

//print out all the point's x and y values
void Convex::printPoints() {
	for (int i = 0; i < points.size(); i++) {
		cout << "(" << points[i].x << ", " << points[i].y  << ")" << endl;
	}
}