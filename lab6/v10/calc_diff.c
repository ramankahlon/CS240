#include <stdio.h>

void calc_diff(int vecsize, float *x, float *y, float *u)
{
	int i;
	for(i=0;i<vecsize;i++)//for loop to calculate difference between 2 vectors 
    	{
       		*(u+i) = (*(y+i))-(*(x+i));//difference of each individual element
    		//printf("i = %f",*(u+i));//debugging
	}
}
