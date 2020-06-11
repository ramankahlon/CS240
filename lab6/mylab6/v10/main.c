#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "read_vectors.h"
#include "calc_dotmag.h"
#include "calc_diff.h"
#include "calc_power.h"

//int read_vectors(int *, float *, float *);//declare methods read_vectors() and calc_dotmag()
//float calc_dotmag(int, float *, float *, float *, float *); 
//void calc_diff(int, float *, float *, float *);
//void calc_power(int, float *, float *, float *);
 
int main()
{
	int vecsize=0;//variable for size of both vectors 
	float *x,*y,*u,*u2;//declare both input vectors
	
	int val=-1;
	int d = 0;//i=0,j=0,k,l
	int ret = -1;
	float dotprod;//dot product of two vectors
	float xmag,ymag;//magnitude of each vector
	FILE *ofp;    
	
	ofp = fopen("vecout.dat","w");
        if(ofp == NULL)//print error message if output file is unable to open
        {
                fprintf(stderr,"file %s does not exist\n","vecout.dat");
                return -1;
        }

	ret = read_vectors(&vecsize, &x, &y);//call read_vectors to get 2 input vectors from file
	if(ret==-1)//if read_vectors fails to read file vecin.dat
	{
		printf("The input entered is not valid. Please change input and run program again.\n");
        	exit(0);
	}
	//printf("ret = %d\n",ret);//debugging printf lines
	//printf("vecsize = %d\n",vecsize);
        //printf("Printing x and y: \n");
/*	for(d=0;d<vecsize;d++)
        {
	        printf("%.2f ",*(x+d));
                printf("%.2f ",*(y+d));
	}
	printf("\n");
*/	
	dotprod = calc_dotmag(vecsize, x, y, &xmag, &ymag);//call calc_dotmag() method to and store return value (dot product) in dotprod
	//printf("%.2f\n",dotprod);//debugging
	u = malloc(sizeof(float)*(vecsize));//allocate memory for u and u2 based on n (size of each vector)
       	u2 = malloc(sizeof(float)*(vecsize));
        calc_diff(vecsize, x, y, u);
        calc_power(vecsize, x, y, u2);
        fprintf(ofp,"Magnitude of 1st vector = %.2f\n",xmag);//print out magnitudes of each vector and dot product
        fprintf(ofp,"\nMagnitude of 2nd vector = %.2f\n",ymag);
        fprintf(ofp,"\nDot product of 2 vectors = %.2f\n",dotprod);

        fprintf(ofp,"\nDifference of 2 vectors: ");//print out difference of 2 vectors
        for(d=0;d<vecsize;d++)
                fprintf(ofp,"%.2f ",*(u+d));
        fprintf(ofp,"\n");

	//printf("after u");//debugging

	fprintf(ofp,"\nDifference of 2 vectors squared: ");//print out difference of 2 vectors squared
	for(d=0;d<vecsize;d++)
                fprintf(ofp,"%.2f ",*(u2+d));
        fprintf(ofp,"\n");

	fclose(ofp);//close output file vecout.dat after writing is complete

        free(x);//release previusly allocated memory from call to malloc() by calling free()
        free(y);
        free(u);
        free(u2);
}

