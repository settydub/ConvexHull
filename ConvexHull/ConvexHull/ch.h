#pragma once
#ifndef CH_H
#define CH_H
#include <iostream>
#include <vector>
using namespace std;

//generates random points in a 2D plane
class Convex
{
	//holds the point's x and y values
	struct point {
		int x, y;
	};
	//holds the max and min x and y values for all points
	int maxX, maxY, minX, minY;
	//the number of points in the plain
	int numPoints;
	//holds all the points on the plane
	vector<point> points;
	//maximum value for a point
	int pointMax;
public:
	//constructor
	Convex(int np, int mxX, int mxY, int mnX, int mnY);
	//generates all the random points
	void generatePoints();
	//print points
	void printPoints();
};

#endif