#include "vectorMult.h"


using namespace std;

void vektorovySoucin(double a[3], double b[3], double c[3]) {
	c[0] = a[0] * b[1] - b[0] * a[1];
	c[1] = a[1] * b[2] - b[1] * a[2];
	c[2] = a[2] * b[0] - b[2] * a[0];
	printf("A * B: (% f, % f, % f)\n", c[0], c[1], c[2]);

}