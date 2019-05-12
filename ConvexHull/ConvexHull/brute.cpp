#include "ch.h"

void Convex::bruteForce() {
	//the first point
	for (int i = 0; i < points.size(); i++)
	{
		//the second point
		for (int j = i + 1; j < points.size(); j++)
		{
			//positive and negative indicators
			int pos = 0, neg = 0;
			//setting the change in y
			int alpha = points[i].y - points[j].y;
			//setting the change in x
			int beta = points[j].x - points[i].x;
			//setting the formula for determining where a point lies in relation to the line
			int delta = (points[i].x * points[j].y) - (points[i].y * points[j].x);
			//checking where every point is in relation to the line
			for (int k = 0; k < points.size(); k++)
			{
				//determines if it is generally negative about the line
				if ((alpha* points[k].x) + (beta* points[k].y) + delta <= 0) neg++;
				//determines if it is generally positive about the line
				if ((alpha* points[k].x) + (beta* points[k].y) + delta >= 0) pos++;
			}
			// if all the points are on one side or the other
			if (pos == points.size() || neg == points.size())
			{
				//place both points in the solution set
				solPoints.push_back(points[i]);
				solPoints.push_back(points[j]);
			}
		}
	}
}