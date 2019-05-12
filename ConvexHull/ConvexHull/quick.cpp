#include "ch.h"

//start of the quickHull process
void Convex::quick() {
	int minX = 0, maxX = 0;
	for (int i = 1; i < numPoints; i++)
	{
		//find the point with smallest x value
		if (points[i].x < points[minX].x) minX = i;
		//find the point with largest x value
		if (points[i].x > points[maxX].x) maxX = i;
	}
	//recursively divide and conquer to find solution lines
	quickHull(points[minX], points[maxX], 1);
	quickHull(points[minX], points[maxX], -1);
}

//determines which points to include in convex hull
void Convex::quickHull(point alpha, point beta, int pos){
	int loc = -1;
	int maxDist = 0;
	//point to check against the line alpha-beta
	for (int i = 0; i < numPoints; i++)
	{
		//find point distance away from alpha-beta
		int t = abs((points[i].y - alpha.y) * (beta.x - alpha.x) - (beta.y - alpha.y) * (points[i].x - alpha.x));
		//if the point is on the right side of the line alpha-beta
		if (location(alpha, beta, points[i]) == pos && t > maxDist){
			loc = i;
			maxDist = t;
		}
	}
	//if no points located, push end points
	if (loc == -1){
		solPoints.push_back(alpha);
		solPoints.push_back(beta);
		return;
	}
	//divide and conquer recursively
	quickHull(points[loc], alpha, -(location(points[loc], alpha, beta)));
	quickHull(points[loc], beta, -(location(points[loc], beta, alpha)));
}

//determines where point lies in relation to line
int Convex::location(point alpha, point beta, point delta)
{
	int val = ((delta.y - alpha.y) * (beta.x - alpha.x)) - ((beta.y - alpha.y) * (delta.x - alpha.x));
	if (val > 0) return 1;
	if (val < 0) return -1;
	return 0;
}