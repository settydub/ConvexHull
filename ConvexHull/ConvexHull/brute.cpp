#include "ch.h"

void Convex::bruteForce() {
	int below = 0;
	int above = 0;
	//the first point
	for (point alpha : points) {
		//the second point
		for (point beta : points) {
			//if they are not the same point
			if (alpha.x != beta.x && alpha.y != beta.y) {
				//a point to compare against
				for (point delta : points) {
					//if the point is not the same as the previous 2 points
					if (delta.x != alpha.x && delta.y != alpha.y && delta.x != beta.x && delta.y != beta.y) {
						//position of the point compared to the line between alpha and beta
						double pos = ((beta.x - alpha.x)*(beta.y - delta.y)) - ((beta.y - alpha.y)*(beta.x - delta.x));
						//if positive, below
						if (pos > 0)
							below++;
						//if negative, above
						else if (pos < 0)
							above++;
						else
						{
							//line from alpha to delta
							line temp;
							temp.x1 = alpha.x;
							temp.y1 = alpha.y;
							temp.x2 = delta.x;
							temp.y2 = delta.y;
							hullLines.push_back(temp);
							//line from delta to beta
							temp.x1 = delta.x;
							temp.y1 = delta.y;
							temp.x2 = beta.x;
							temp.y2 = beta.y;
							hullLines.push_back(temp);
						}
					}
				}
				//if all the points are below or above
				if (below == (points.size() - 2) || above == (points.size() - 2))
				{
					//line from alpha to beta
					line temp;
					temp.x1 = alpha.x;
					temp.y1 = alpha.y;
					temp.x2 = beta.x;
					temp.y2 = beta.y;
					hullLines.push_back(temp);
				}
			}
		}
	}
	cleanSolution();
}