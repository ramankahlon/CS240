#include <stdio.h>
#include "math.h"
//#include <read_vectors.h>
//#include <calc_dotmag.h>

int read_vectors(int *, float *, float *);//declare methods read_vectors() and calc_dotmag()
float calc_dotmag(int , float *, float *, float *, float *); 
void calc_diff(int,float *,float *,float *);
int MAXSIZE = 50;//declare and initialize variable for maximum size of vector input
 
int main()
{
    int vecsize=0;//variable for size of both vectors 
    float x[MAXSIZE],y[MAXSIZE],u[MAXSIZE];//declare both input vectors
    int val=-1;
    int d = 0,k,l;
    float dotprod;//dot product of two vectors
    float xmag,ymag;//magnitude of each vector
 /*
    if(val == -1)//check for whether input arrays are valid. If not, execute this if statement
    {
	printf("\nThe input entered is not valid. Please re-enter a number.\n");
        exit(-1);
    }
*/
    while(val == -1)
    {
	val = read_vectors(&vecsize,x,y);//call method read_vectors() with two input arrays as parameters and store 0 if the vectors are valid and -1 if they are invalid
    	if(val == -1)
        	printf("\nThe input entered is not valid. Please re-enter a number.\n");
    }
//  printf("\n = %d\n",vecsize);//print out vector size (debugging)
/*
    printf("Array 1: \n");//print out array 1 (debugging)
    for(k=0;k<vecsize;k++)
        printf("%.2f ",x[k]);

    printf("Array 2: \n");//print out array 2 (debugging)
    for(l=0;l<vecsize;l++)
        printf("%.2f ",y[l]);
*/
    dotprod = calc_dotmag(vecsize, x, y, &xmag, &ymag);//call calc_dotmag() method to and store return value (dot product) in dotprod 
    calc_diff(vecsize, x, y, u);
    printf("\nMagnitude of 1st vector = %.2f\n",xmag);//print out magnitudes of each vector and dot product
    printf("\nMagnitude of 2nd vector = %.2f\n",ymag);
    printf("\nDot product of 2 vectors = %.2f\n",dotprod);
    
    printf("\nDifference of 2 vectors: ");
    for(d=0;d<vecsize;d++)
       printf("%.2f ",u[d]);
    printf("\n");
}

