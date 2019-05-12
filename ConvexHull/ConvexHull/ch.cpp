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

//creates a bunch of random points (no duplicates, close to true random)
void Convex::generatePoints()
{
	random_device r;
	mt19937 gen(r());
	uniform_int_distribution<> distrX(minX, maxX);
	uniform_int_distribution<> distrY(minY, maxY);
	int count = 0;
	while (count < numPoints) {
		point temp;
		temp.x = distrX(gen);
		temp.y = distrY(gen);
		bool isThere = false;
		for (int i = 0; i < points.size(); i++) {
			if (temp.x == points[i].x && temp.y == points[i].y)
				isThere = true;
		}
		if (isThere == false)
		{
			points.push_back(temp);
			count++;
		}
	}
}

//print out all the point's x and y values
void Convex::printPoints() {
	cout << "Points" << endl;
	for (int i = 0; i < points.size(); i++) {
		cout << "(" << points[i].x << ", " << points[i].y  << ") " << endl;
	}
	cout << endl;
}

//print out all the line points that make the solution for the hull
void Convex::printLines() {
	cout << "Solution Lines" << endl;
	for (int i = 0; i < solPoints.size() - 1; i+=2) {
		cout << "(" << solPoints[i].x << ", " << solPoints[i].y << ") to (" << solPoints[i + 1].x << ", " << solPoints[i + 1].y << ") " << endl;
	}
	solPoints.clear();
	cout << endl;
}