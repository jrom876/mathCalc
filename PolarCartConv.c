
//===========================================================
//
//  File Name:          PolarCartConv.c
//  Project Name:       toolbox
//  Code Writer: 	Jacob M. Romero
//
//===========================================================

// https://en.wikipedia.org/wiki/Spherical_coordinate_system
// https://blog.demofox.org/2013/10/12/converting-to-and-from-polar-spherical-coordinates-made-easy

#include <check.h>
#include <inttypes.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "PolarCartConv.h"

struct Cartesian_2D createCartesian_2D (float x, float y) {
	struct Cartesian_2D cp;
	cp.xcoord = ((x > XMAX) || (x < XMIN)) ? XMIN : x;
	cp.ycoord = ((y > YMAX) || (y < YMIN)) ? YMIN : y;
	printf("\nINITIAL CARTESIAN VALUES: \n"); // DBPRINT
	printf("%.3f : %.3f\n",cp.xcoord,cp.ycoord); //DBPRINT
	return cp;
}


struct Cartesian_3D createCartesian_3D (float x, float y, float z) {
	struct Cartesian_3D cp;
	cp.xcoord = ((x > XMAX) || (x < XMIN)) ? XMIN : x;
	cp.ycoord = ((y > YMAX) || (y < YMIN)) ? YMIN : y;
	cp.zcoord = ((z > ZMAX) || (z < ZMIN)) ? ZMIN : z;
	printf("\nINITIAL CARTESIAN VALUES: \n"); // DBPRINT
	printf("%.3f : %.3f : %.3f\n",cp.xcoord,cp.ycoord,cp.zcoord); //DBPRINT
	return cp;
}

struct Polar createPolar(float r, float thetaDeg){
	struct Polar pp;
	pp.radius = (r >= 0) ? r : 0;
	//float thetaRad = thetaDeg * PI/180.0;
	pp.thetaDegrees = thetaDeg;
	printf("\nINITIAL POLAR VALUES: \n"); // DBPRINT
	printf("%.3f : %.3f\n",pp.radius,pp.thetaDegrees); //DBPRINT
	return pp;
}

struct Spherical createSpherical(float r, float thetaDeg, float phiDeg){
	struct Spherical sp;
	sp.radius = (r >= 0) ? r : 0;
	//float thetaRad = thetaDeg * PI/180.0;
	sp.thetaDegrees = thetaDeg;
	sp.phiDegrees = phiDeg;
	printf("\nINITIAL POLAR VALUES: \n"); // DBPRINT
	printf("%.3f : %.3f : %.3f\n",sp.radius,
			sp.thetaDegrees,sp.phiDegrees); //DBPRINT
	return sp;
}

/**
 * CONVERSION FUNCTIONS
 * **/

struct Cartesian_2D polarToCartesian(float radius, float thetaDegrees) {
	float theta = thetaDegrees * PI/180.0;
	float xc = radius * cos(theta);
	float yc = radius * sin(theta);
	struct Cartesian_2D cp0 = createCartesian_2D(xc,yc);
	printf("Polar to Cartesian: radians = %.3f\t Degrees = %.3f\t distance = %.3f\n",
			theta,thetaDegrees,radius);
	printf("xc:  %.3f  yc:  %.3f \n\n",xc,yc);
	return cp0;
}

struct Polar cartesianToPolar(float x, float y){
	float r = sqrt((x*x)+(y*y));
	float thetaRad = atan(sqrt((x*x)+(y*y)));
	float thetaDeg = thetaRad * (180.0/PI);
	float xc = r * cos(thetaRad);
	float yc = r * sin(thetaRad);
	struct Polar p0 = {r,thetaDeg};
	printf("thetaDegrees:  %.5f  radius:  %.5f\n",thetaDeg,r);
	printf("xc:  %.3f\tyc:  %.3f\n",xc,yc);
	return p0;
}

struct Cartesian_3D sphericalToCartesian(float radius, float thetaDegrees, float phiDegrees) {
	float theta = thetaDegrees * PI/180.0;
	float xc = radius * cos(theta);
	float yc = radius * sin(theta);
	float zc = radius;
	struct Cartesian_3D cp0 = createCartesian_3D(xc,yc,zc);
	printf("Polar to Cartesian: radians = %.3f\t Degrees = %.3f\t distance = %.3f\n",
			theta,thetaDegrees,radius);
	printf("xc:  %.3f  yc:  %.3f  zc:  %.3f\n\n",xc,yc,zc);
	return cp0;
}

struct Spherical cartesianToSpherical(float x, float y, float z){
	float r = sqrt((x*x)+(y*y)+(z*z));
	float thetaRad = atan((sqrt((x*x)+(y*y)))/z);
	float thetaDeg = thetaRad * (180.0/PI);
	float phiRad = (x >= 0) ? atan(y/x) : atan((y/x)+PI);
	float phiDeg = phiRad * (180.0/PI);
	float xc = r * cos(thetaRad);
	float yc = r * sin(thetaRad);
	float zc = r;
	struct Spherical s0 = {r,thetaDeg,phiDeg};
	printf("\n radius: %.5f\tthetaDegrees: %.3f\tphiDegrees: %.3f\n",r,thetaDeg,phiDeg);
	printf("xc:  %.3f  yc:  %.3f  zc:  %.3f\n",xc,yc,zc);
	return s0;
}

/**
 * COORDINATE CALCULATORS
 * **/

float calcRadialDistance_R (float x, float y, float z) {
	float radius = sqrt((x*x) + (y*y) + (z*z));
	printf("radius = %f\n",radius);
	return radius;
}

float calcPolarAngle_Theta (float x, float y) {
	float thetaRad = atan(y/x);
	printf("theta = %f\n",theta);
	return theta;
}

float calcAzimuthAngle_Phi (float x, float y, float z) {
	float radius = sqrt((x*x) + (y*y) + (z*z));
	float phiRad = acos(z/radius);
	printf("phi = %.4f\tradius = .4%f\n",phi,radius);
	return phi;
}

/**
 * YE OLD MAIN
 **/
int main(int argc, char const *argv[]) {
	struct Cartesian_2D c2d =  createCartesian_2D(2,3);
	createCartesian_3D(12,18,24);
	struct Polar p0 = createPolar(5.0, 30.0);
	struct Spherical s0 = createSpherical(5.0, 30.0, 30.0);
	polarToCartesian(p0.radius, p0.thetaDegrees);
	cartesianToPolar(c2d.xcoord, c2d.ycoord);
	sphericalToCartesian(s0.radius, s0.thetaDegrees, s0.phiDegrees);
	return 0;
}
