#include <stdio.h>
#include "math.h"
#include <stdlib.h>
//#include <read_vectors.h>
//#include <calc_dotmag.h>
//#include <calc_diff.h>
//#include <calc_power.h>

//int read_vectors(int *, float *, float *);//declare methods read_vectors() and calc_dotmag()
//float calc_dotmag(int, float *, float *, float *, float *); 
//void calc_diff(int, float *, float *, float *);
//void calc_power(int, float *, float *, float *);
int MAXSIZE = 50;//declare and initialize variable for maximum size of vector input
 
int main()
{
	int vecsize=0;//variable for size of both vectors 
	float x[MAXSIZE],y[MAXSIZE],u[MAXSIZE],u2[MAXSIZE];//declare both input vectors
	
	int val=-1;
	int d = 0,i=0,j=0,k,l,ret=-1;
	float dotprod;//dot product of two vectors
	float xmag,ymag;//magnitude of each vector
    	
	ret = read_vectors(&vecsize, x, y);
	if(ret==-1)
	{
		printf("The input entered is not valid. Please change input and run program again.");
        	return -1;
	}
	dotprod = calc_dotmag(vecsize, x, y, &xmag, &ymag);//call calc_dotmag() method to and store return value (dot product) in dotprod
        calc_diff(vecsize, x, y, u);
        calc_power(vecsize, x, y, u2);
        printf("\nMagnitude of 1st vector = %.2f\n",xmag);//print out magnitudes of each vector and dot product
        printf("\nMagnitude of 2nd vector = %.2f\n",ymag);
        printf("\nDot product of 2 vectors = %.2f\n",dotprod);

        printf("\nDifference of 2 vectors: ");//print out difference of 2 vectors
        for(d=0;d<vecsize;d++)
                printf("%.2f ",u[d]);
        printf("\n");

}

