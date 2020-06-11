#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "read_vectors_complex.h"
#include "calc_dotprod_complex.h"

int MAXSIZE;

complex_num_t * calc_dotprod_complex(int vecsize, complex_num_t **a, complex_num_t **b)
{
	//declare and initialize variables for sums of same components of each array (sum1, sum2) and product of both arrays (prod1, prod2) 
	float sum1 = 0,sum2 = 0,prod1 = 0,prod2 = 0;
	complex_num_t *total;//total variable to hold sum1,sum2,prod1, and prod2
	//printf("Before calloc\n");//debugging
	total = calloc(sizeof(complex_num_t),vecsize*2);//allocate memory for total
	//printf("After calloc\n");//debugging

	int i;
    	for(i=0;i<vecsize;i++)//for loop to calculate sum of two complex numbers a and b
    	{
		//printf("i = %d\n",i);//debugging
		sum1 = (*a)[i].x + (*b)[i].x;//sum of x components
		sum2 = (*a)[i].y + (*b)[i].y;//sum of y components
		//printf("After sum =  %f + %fi\n",sum1,sum2);//debugging
		total[i].x = sum1;//store sums in single complex_num_t * variable total
		total[i].y = sum2;
	}

	for(i=0;i<vecsize;i++)//for loop to calculate product of two complex numbers a and b
	{
		prod1 = ((*a)[i].x) * ((*b)[i].x) - ((*a)[i].y) * ((*b)[i].y);//product of x components
		prod2 = ((*a)[i].x) * ((*b)[i].y) + ((*a)[i].y) * ((*b)[i].x);//proudct of y components
		total[vecsize + i].x = prod1;//store products in same complex_num_t * variable total
		total[vecsize + i].y = prod2;

		//printf("After total = %f + %fi\n",sum1,sum2);//debugging
	}
	return total;
}
