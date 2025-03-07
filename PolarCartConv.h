
// PolarCartConv.h 
#ifndef POLARCARTCONV_H
#define POLARCARTCONV_H

/// STANDARD DEFINITIONS FOR PROJECT SCICALC 
#define PI	3.14159265358979323846 // ad infinitum
#define LIGHT_SPEED		299792458 // meters per second
#define DATA_SIZE 1000
#define DELTA 1.0e-6
#define KILO 1000
#define MEGA 1000000
#define GIGA 1000000000
#define TERA 1000000000000 

#define XMAX 0xFFFF
#define YMAX 0xFFFF
#define ZMAX 0xFFFF
#define XMIN 1
#define YMIN 1
#define ZMIN 1

/** 
 * DATA STRUCTURES
**/

struct Cartesian_2D {
	float xcoord;
	float ycoord;
};

struct Cartesian_3D {
	float xcoord;
	float ycoord;
	float zcoord;
};

struct Polar {
	float radius;
	float thetaDegrees;
};

struct Spherical {
	float radius;
	float thetaDegrees;
	float phiDegrees;
};

struct Cartesian_2D createCartesian_2D	(float x, float y);
struct Cartesian_3D createCartesian_3D	(float x, float y, float z);

struct Polar 		createPolar		(float r, float thetaDeg);
struct Spherical 	createSpherical	(float r, float thetaDeg, float phiDeg);

/** 
 * CONVERSION FUNCTIONS
**/
struct Cartesian_2D polarToCartesian	(float radius, float thetaDegrees);
struct Cartesian_3D sphericalToCartesian(float radius, float thetaDegrees, float phiDegrees);

struct Polar cartesian2D_ToPolar	(float x, float y);
struct Spherical cartesian3D_ToPolar(float x, float y, float z);

/** 
 * COORDINATE CALCULATORS
**/
float calcRadialDistance_R 	(float x, float y, float z);
float calcPolarAngle_Theta 	(float x, float y);
float calcAzimuthAngle_Phi 	(float x, float y, float z);

#endif

