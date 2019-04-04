#include "ch.h"

int main() {
	//number of points, maximum x, maximum y, minimum x, minimum y
	Convex c(10, 10, 10, 0, 0);
	c.generatePoints();
	c.printPoints();
	system("pause");
	return 0;
}