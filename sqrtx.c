/* File: srqtx.c
Calculate square root(num) using Newton's Method
*/

#include <stdio.h>
#include <math.h>	// For fabs()
#include <float.h>	// For FLT_EPSILON
#include "sqrtx.h"

#define N 100	// The maximum number of iterations

double sqrt(double num){	
	int i;
	double x0, x1, x2;
	x0 = num;		// an initial guess for x0
	x1 = x0;		// Set x1 to x0
	for (i=1; i<=N; i++) {
		x2 = (x1 + num/x1)/2.0;
		if (fabs(x2-x1) < FLT_EPSILON)
			break;
		x1 = x2;	// update x1 for next iteration
		printf("x2 = %lf\n",x2); // DBPRINT
	}
	if (i<N)	// Number of iterations < N
	{
		printf("\nsqrtx(%.2f) = %lf\n", num, x2); // DBPRINT
		return x2;
	}
	else {		// Number of iterations = N
		printf("sqrtx failed to converge\n");
		return -1;
	}
}

int main() {
	double a;
	printf("Enter number: ");
	scanf("%lf", &a);
	sqrt(a);
}
