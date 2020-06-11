#include <stdio.h>
#include <math.h>

float calc_dotmag(int vecsize, float *x, float *y, float *xmag, float *ymag)
{
	float xsum = 0;//declare and initialize variables for sums of each array (xsum,ysum) and dot product of both arrays (product) 
    	float ysum = 0;
    	float product = 0;
    	int i;
    	for(i=0;i<vecsize;i++)//for loop to calculate sums of two arrays and dot product
    	{
       		xsum += (*(x+i))*(*(x+i));//sum of 1st array (addition of each element)
       		ysum += (*(y+i))*(*(y+i));//sum of 2nd array
       		product += (*(x+i))*(*(y+i));//dot product of 1st and 2nd arrays
    	}
   	*xmag = sqrt(xsum);//magnitude of 1st array 
   	*ymag = sqrt(ysum);//magnitude of 2nd array
   	return product;
}

