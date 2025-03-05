
//	Package:	tools
//	File:		mathCalc.c 
//	Purpose:	Provide methods for integrals, derivatives, and other
//				math functions not inherent in C language libraries
//	Author:		jrom876

/**
	Copyright (C) 2019, 2021 
	Jacob Romero, Creative Engineering Solutions, LLC
	cesllc876@gmail.com
	admin@jrom.io 

	This program is free software; you can redistribute it
	and/or modify it under the terms of the GNU General Public  
	License as published by the Free Software Foundation, version 2.

	This program is distributed in the hope that it will be
	useful, but WITHOUT ANY WARRANTY; without even the implied 
	warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
	
	See the GNU General Public License for more details.
	
	You should have received a copy of the GNU General Public
	License along with this program; if not, write to:
	The Free Software Foundation, Inc.
	59 Temple Place, Suite 330
	Boston, MA 02111-1307 USA
**/

#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>    /* Standard Library of Complex Numbers */
#include "mathCalc.h"

/// STANDARD DEFINITIONS FOR PROJECT SCICALC 
#define PI	3.14159265358979323846 // ad infinitum
#define LIGHT_SPEED		299792458 // meters per second
#define DATA_SIZE 1000
#define DELTA 1.0e-6
#define KILO 1000
#define MEGA 1000000
#define GIGA 1000000000
#define TERA 1000000000000 

double integral(double(*f)(double x), double a, double b, int n) {
    double step = (b - a) / n;  // width of each small rectangle
    double area = 0.0;  // signed area
    for (int i = 0; i < n; i ++) {
        area += f(a + (i + 0.5) * step) * step; // sum up each small rectangle
    }
    printf("%lf\n", area); // DBPRINT
    return area;
}

double derive(double (*f)(double), double x0) {
	double result;
    //~ const double delta = 1.0e-6; // or similar
    const double delta = DELTA; 
    double x1 = x0 - delta;
    double x2 = x0 + delta;
    double y1 = f(x1);
    double y2 = f(x2);
    result = (y2 - y1) / (x2 - x1);
    printf("%lf",result); // DBPRINT
    return (y2 - y1) / (x2 - x1);
}

int main(int argc, char const *argv[]) {
	double integ1 = integral(sin, 0, PI/4, 10);
	double integ2 = integral(cos, 0, PI/2, 10);
	double integ3 = integral(cos, 0, PI/2, MEGA);
	printf("integral 1\t%lf\n", integ1); // should be around 0.292969
	printf("integral 2\t%lf\n", integ2); // should be around 1.0
	printf("integral 3\t%lf\n", integ3); // should be exactly 1.0
	
	double phi = (PI/3)/2;
	//~ double der = derive(sin, 0.0);
	double der = derive(sin, 0.0);
	printf("\nderivative 0\t%lf\n", der); // should be around 1.0
	double der1 = derive(sin, ((2*PI)+ phi));
	printf("\nderivative 1\t%lf\n", der1); // should be around 1.0
	return 0;
}

//////////////////////////////////////////////////////////////////////

//~ ________________________________________________________________
//~ FORMAT SPECIFIER               ::          DESCRIPTION
//~ ________________________________________________________________
//~ %c                                          Character       
//~ %d                                       Signed Integer 

//~ %e or %E                              Scientific notation

//~ %f                                       Floating point

//~ %g or %G.                             Similar as %e or %E

//~ %hi.                                     Signed Integer

//~ %hu                                 Unsigned Integer(Short) 

//~ %i                                       Signed Integer

//~ %l or %ld or %li                         Signed Integer

//~ %lf                                      Floating point

//~ %Lf                                      Floating point 

//~ %lu                                     Unsigned integer

//~ %lli, %lld                            Signed long long int

//~ %llu.                                unsigned long long int

//~ %o.                              Octal representation of Integer.

//~ %p                              Address of pointer to void void *   
                                              //~ void *

//~ %s                                       String char *
//~ %u                                       Unsigned int 

                                      //~ Unsigned short int 

//~ %n                                      Prints nothing

//~ %%                                    Prints % character

//~ %o                                   Octal representation 

//~ %p                            Address of pointer to void void * 
                                             //~ void *

//~ %s                                       String char *

//~ %u                                     Unsigned Integer 

//~ %x or %X                         Hexadecimal representation of 
                                         //~ Unsigned Int.

//~ %n                                      Prints nothing  

//~ %%                                   Prints % character
//~ ________________________________________________________________


///**********************************************************************
/// typedef void (*FunctionCallback)(int) 
/// This is the only way we can use scanf (see our obligatory
///  getUserInputMATH interface at the bottom of this file) 
/// to call a function such as sin, cos or any custom functions.

//~ // function type
//~ typedef void (*FunctionCallback)(int);
//~ FunctionCallback functions[] = {
	//~ &foo, 
	//~ &bar
//~ };

//~ int foo () {
	//~ double x = 0;
	//~ double(*slope_int)(double x);
	//~ double result = slope_int(2*x);
//~ }

///**********************************************************************

/////////////////////////////////////////////
// https://stackoverflow.com/questions/1118705/call-a-function-named-in-a-string-variable-in-c
//~ #include <stdio.h>

//~ // functions
//~ void foo(int i);
//~ void bar(int i);

//~ // function type
//~ typedef void (*FunctionCallback)(int);
//~ FunctionCallback functions[] = {&foo, &bar};

//~ int getUserInputMATH(){
	//~ double (*funct)(double);
	//~ double ll, ul, x;
	//~ char * string;
	//~ int num, size = 40;
  	//~ int exitFlag = 0;
	//~ int var;
	//~ printf("Please choose from the following: \n");
	//~ printf("1 to integrate \n");
	//~ printf("2 to derive \n");
	//~ printf("8 for quit\n");
	//~ scanf(" %i", &var);
	//~ switch (var) {
		//~ case 1:
			//~ printf("Please enter function: \n");
			//~ scanf("%s", &string);
			//~ funct = (double *)string;
			//~ fgets(x,size,stdin);
			//~ funct = (double *)string;
			//~ printf("Please enter bottom limit: \n");
			//~ scanf(" %lf", &ll);
			//~ printf("Please enter upper limit: \n");
			//~ scanf(" %lf", &ul);
			//~ printf("Please enter number of integrations (rectangles): \n");
			//~ scanf(" %d", &num);
			//integral(string,ll,ul,num);
      			//~ break;
		//~ case 2:

			//~ break;
		//~ case 8:
			//~ printf("Quitting\n");
			//~ exitFlag = 1;
			//~ break;
		//~ default:
			//~ printf("Wrong choice. Now exiting.\n");
			//~ exit(0);
			//~ break;
	//~ }
	//~ if(0 != exitFlag) return 0;
	//~ getUserInputMATH();
//~ }

//~ int main(void)
//~ {
    //~ // get function id
    //~ int i = 0;
    //~ scanf("%i", &i);

    //~ // check id
    //~ if( i >= sizeof(functions))
    //~ {
        //~ printf("Invalid function id: %i", i);
        //~ return 1;
    //~ }

    //~ // call function
    //~ functions[i](i);

    //~ return 0;
//~ }

//~ void foo(int i)
//~ {
    //~ printf("In foo() with: %i", i);
//~ }

//~ void bar(int i)
//~ {
    //~ printf("In bar() with: %i", i);
//~ }
////////////////////////////////////////////

// https://helloacm.com/c-function-to-compute-numerical-integral-using-function-pointers/
// https://stackoverflow.com/questions/6418807/how-to-work-with-complex-numbers-in-c
// https://www.antenna-theory.com/basics/impedance.php
// https://en.wikipedia.org/wiki/Complex_conjugate
// https://www.techiedelight.com/return-multiple-values-function-c/

// https://stackoverflow.com/questions/25036175/what-could-be-the-expression-double-fdouble-in-c-mean
// https://stackoverflow.com/questions/9410/how-do-you-pass-a-function-as-a-parameter-in-c
// https://stackoverflow.com/questions/1118705/call-a-function-named-in-a-string-variable-in-c
// https://stackoverflow.com/questions/26397184/c-control-strings
// https://vitux.com/three-ways-to-listen-to-radio-via-ubuntu-terminal/
