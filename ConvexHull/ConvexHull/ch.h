#pragma once
#ifndef CH_H
#define CH_H
#include <iostream>
#include <vector>
#include <random>
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
	//the number of points in the plane
	int numPoints;
	//holds all the points on the plane
	vector<point> points;
	//holds all the points for the solution lines
	vector<point> solPoints;
	//maximum value for a point
	int pointMax;
public:
	//constructor
	Convex(int np, int mxX, int mxY, int mnX, int mnY);
	//generates all the random points
	void generatePoints();
	//print points
	void printPoints();
	//print solution lines
	void printLines();
	//calculates convex hull using brute force
	void bruteForce();
	//starter helper method for quickHull
	void quick();
	//calculates convex hull using quickHull
	void quickHull(point alpha, point beta, int pos);
	//determines where a point lies in relation to a line
	int location(point alpha, point beta, point delta);
};

#endif