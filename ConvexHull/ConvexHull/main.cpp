#include "ch.h"
#include <iostream>
#include <iomanip>
#include <ctime>
#include <chrono>

int main() {
	//analysis variables
	int bCount = 0;
	int qCount = 0;
	chrono::steady_clock::time_point start;
	chrono::steady_clock::time_point end;

	const int iterate = 10;
	for (int i = 0; i < iterate; i++)
	{
		//number of points, maximum x, maximum y, minimum x, minimum y
		Convex c(5, 100, 100, 0, 0);
		//generates the points
		c.generatePoints();
		//prints the points
		c.printPoints();

		//measure the time it takes for bruteForce
		cout << "Brute Force" << endl;
		start = chrono::steady_clock::now();
		c.bruteForce();
		end = chrono::steady_clock::now();
		//prints the solution lines
		c.printLines();
		//print duration of algorithm
		cout << "Duration: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " microseconds" << endl << endl;
		bCount += chrono::duration_cast<chrono::microseconds>(end - start).count();

		//measure the time it takes for bruteForce
		cout << "Quickhull" << endl;
		start = chrono::steady_clock::now();
		c.quick();
		end = chrono::steady_clock::now();
		//prints the solution lines
		c.printLines();
		//print duration of algorithm
		cout << "Duration: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " microseconds" << endl << endl;
		qCount += chrono::duration_cast<chrono::microseconds>(end - start).count();
	}
	//print average duration of algortihms
	cout << "Average Duration of Brute Force: " << bCount/ iterate << " microseconds" << endl;
	cout << "Average Duration of Quickhull: " << qCount / iterate << " microseconds" << endl;
	system("pause");
	return 0;
}