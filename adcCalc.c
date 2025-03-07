
/* 
 * File:		adcCalc.c
 * Author:		Jake Romero
 * Company:		Creative Engineering Solutions, LLC
 * Email:		cesllc876@gmail.com
 * 
 * Purpose:		Calculates the value read by an ADC 
 * Call:		adc_map (int adc_value, int adc_min, int adc_max, float out_min, float out_max)
 * Algorithm:	adcResult = ((((adc_value-adc_min)*(out_max-out_min))/(adc_max-adc_min))+out_min)
 * Reference:	https://stackoverflow.com/questions/61000446/map-function-implementation-in-c
 * 
 */

#include <stdio.h>
#include <string.h>
#include <curses.h> // use this for Linux machines
//#include <conio.h> // use this for Windows machines

int main () {
	//// Comment these in for normal operation
	int adc_value, adc_min, adc_max;
	float out_min, out_max, adcResult;
	
	//// Comment these in for test
	//~ int adc_value=2456, adc_min=0, adc_max=4096;
	//~ float out_min=0, out_max=12, adcResult;
	
	printf("\nadc_map Function: Calculates the value read by an ADC \n");
	printf("\nFunction Call:\tadc_map (int adc_value, int adc_min, int adc_max, float out_min, float out_max)");
	printf("\nAlgorithm:\tadcResult = ((( (adc_value - adc_min) * (out_max-out_min) ) / (adc_max-adc_min)) + out_min)");
	printf("\nadc_value:\tthe ADC value to map");
	printf("\nadc_min:\tthe lower bound of the ADC value’s current range");
	printf("\nadc_max:\tthe upper bound of the ADC value’s current range");
	printf("\nout_min:\tthe lower bound of the output value’s target range");
	printf("\nout_max:\tthe upper bound of the output value’s target range\n");

	//// Comment these in for normal operation, comment out for test		
	printf("\nEnter adc_value: ");
	scanf("%d",&adc_value);
	printf("Enter adc_min: ");
	scanf("%d",&adc_min);
	printf("Enter adc_max: ");
	scanf("%d",&adc_max);
	printf("Enter out_min: ");
	scanf("%f",&out_min);
	printf("Enter out_max: ");
	scanf("%f",&out_max);
	
	adcResult = (( ((adc_value - adc_min)*(out_max-out_min)) / (adc_max-adc_min) ) + out_min);	
	printf("\nadcResult: %f\n\n", adcResult);
	return 0;
}
