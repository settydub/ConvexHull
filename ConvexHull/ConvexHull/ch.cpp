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
		cout << "(" << points[i].x << ", " << points[i].y  << ")" << endl;
	}
}

//print out all the line points that make the solution for the hull
void Convex::printLines() {
	cout << "Solution Lines" << endl;
	for (int i = 0; i < hullLines.size(); i++) {
		cout << "(" << hullLines[i].x1 << ", " << hullLines[i].y1 << ") to (" << hullLines[i].x2 << ", " << hullLines[i].y2 << ")" << endl;
	}
}

//removes duplicate lines from solution set
void Convex::cleanSolution() {
	for (int i = 0; i < hullLines.size(); i++) {
		for (int j = 0; j < hullLines.size(); j++) {
			if (hullLines[i].x1 == hullLines[j].x2 && hullLines[i].x2 == hullLines[j].x1 && hullLines[i].y1 == hullLines[j].y2 && hullLines[i].y2 == hullLines[j].y1
				|| (hullLines[i].x1 == hullLines[j].x1 && hullLines[i].x2 == hullLines[j].x2 && hullLines[i].y1 == hullLines[j].y1 && hullLines[i].y2 == hullLines[j].y2)) {
				hullLines.erase(hullLines.begin() + j);
			}
		}
	}
}