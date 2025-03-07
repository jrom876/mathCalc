
//	Package:	tools
//	File:		delay.c 
//	Path:		~/tools/delay/delay.c
//	Purpose:	The obligatory and ubiquitous C delay function, 
//				which is not inherent in C language libraries
//	Author:		jrom876

//	There are three methods:
// 		delay		(int tim)
// 		delay_ms	(int tim)
// 		delay_sec	(int tim) 
//

#include <stdio.h>
#include <time.h>
#include "delay.h"

void delay_sec(int tim){
  tim = 1000000 * tim;
  clock_t start_time = clock();
  while (clock() < start_time + tim);
}

void delay_ms(int tim){
  tim = 1000 * tim;
  clock_t start_time = clock();
  while (clock() < start_time + tim);
}

void delay(int tim){
  clock_t start_time = clock();
  while (clock() < start_time + tim);
}

int main()
{
  int delay1;
  printf("Enter delay: ");
  scanf("%d", &delay1);
  printf("Delay in seconds .... wait for it\n");
  delay_sec(delay1);  
  printf("Delay in ms * 1000 .... wait for it\n");
  delay_ms(delay1*1000);  
  printf("Delay in us * 1000000 .... wait for it\n");
  delay(delay1*1000000);  
  printf("Done with delay test\n");
  
  return 0;
}
