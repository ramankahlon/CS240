#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "read_vectors_complex.h"
#include "calc_dotprod_complex.h"
#include "calc_diff.h"
#include "calc_power.h"

int main(int argc, char *argv[])
{
	int vecsize;//declare variable for size of both arrays
	//float *x,*y,*u,*u2;//declare both input vectors
	complex_num_t *vec1,*vec2;

	int d = 0;//variable for indices of dotprod (used in loops to print out sum of vectors and product of vectors
	int ret = -1;//variable for return value of read_vectors_complex (value is -1 if input is invalid, 1 if valid)
	complex_num_t *dotprod;//dot product of two vectors
	float xmag,ymag;//magnitude of each vector

	ret = read_vectors_complex(&vecsize, &vec1, &vec2, argv);//call read_vectors to get 2 input vectors from file

	if(ret==-1)//if read_vectors fails to read either input vector file
	{
		printf("The input entered is not valid. Please change input and run program again.\n");
        	exit(0);
	}
	//printf("ret = %d\n",ret);//debugging printf lines
	//printf("vecsize = %d\n",vecsize);
        //printf("Printing x and y: \n");

/*	
	for(d=0;d<vecsize;d++)//print components of first vector (debugging)
        {
	       printf("%.2f ",(vec1[d].x));
               printf("%.2f ",(vec1[d].y));
	}
	printf("\n");

	for(d=0;d<vecsize;d++)//print components of second vector (debugging)
        {
	       printf("%.2f ",(vec2[d].x));
               printf("%.2f ",(vec2[d].y));
	}
	printf("\n");
*/

	dotprod = calc_dotprod_complex(vecsize, &vec1, &vec2);//call calc_dotmag() method to and store return value (dot product) in dotprod

	printf("\nSum of vectors: \n");
	for(d=0;d<vecsize;d++)//loop to print out sum of complex numbers x and y
        {
	       printf("%.2f ",(dotprod[d].x));
               printf("+ %.2fi\n",(dotprod[d].y));
	}
	printf("\n");

	printf("Product of vectors: \n");
	for(d=vecsize;d<vecsize*2;d++)//loop to print out product of complex numbers x and y
        {
	       printf("%.2f ",(dotprod[d].x));
               printf("+ %.2fi\n",(dotprod[d].y));
	}
	printf("\n");

	//u = malloc(sizeof(float)*(vecsize));//allocate memory for u and u2 based on n (size of each vector)
       	//u2 = malloc(sizeof(float)*(vecsize));
        //calc_diff(vecsize, x, y, u);//not used for this lab
        //calc_power(vecsize, x, y, u2);//not used for this lab

        free(vec1);//release previusly allocated memory from call to malloc() by calling free()
        free(vec2);
	free(dotprod);
}

