#include <stdio.h>
#include <math.h>

int MAXSIZE;

void calc_power(int vecsize, float *x, float *y, float u2[MAXSIZE])
{
    int i;
    for(i=0;i<vecsize;i++)//for loop to calculate difference between 2 vectors
    {
       u2[i] = pow((*(y+i))-(*(x+i)),2);//difference of each individual element squared
	printf("calcpower is %d = %f",i,*(u2+i));
    }
}
