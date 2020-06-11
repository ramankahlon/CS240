#include <stdio.h>
#include "math.h"
#include <stdlib.h>
//#include <read_vectors.h>
//#include <calc_dotmag.h>

int read_vectors(int *, float *, float *);//declare methods read_vectors() and calc_dotmag()
float calc_dotmag(int, float *, float *, float *, float *); 
void calc_diff(int, float *, float *, float *);
void calc_power(int, float *, float *, float *);
int MAXSIZE = 50;//declare and initialize variable for maximum size of vector input
 
int main()
{
	int vecsize=0;//variable for size of both vectors 
	float x[MAXSIZE],y[MAXSIZE],u[MAXSIZE],u2[MAXSIZE];//declare both input vectors
	int val=-1;
	int d = 0,i=0,j=0,k,l;
	float dotprod;//dot product of two vectors
	float xmag,ymag;//magnitude of each vector
    	
	FILE *fp,*ofp;//declare input and output files
	//  int x, y, z;//variables for debugging while scanning input file and writing output file

	//  open file to read

	fp = fopen("vecin.dat","r");//open the input and output files
	ofp = fopen("vecout.dat","w");

	//  open failed

    	if(fp == NULL)//print error message if input file is unable to open
    	{
        	fprintf(stderr,"file %s does not exist\n","vecin.dat");
        	exit(1);
    	}

    	if(ofp == NULL)//print error message if output file is unable to open
    	{
        	fprintf(stderr,"file %s does not exist\n","vecout.dat");
        	exit(1);
    	}

	int n;
	fscanf(fp,"%d",&n);
	vecsize = n;

	int counter = 0;
    	int c;//declare variable c for original ASCII value for character in input file
    	while(counter < n)//while loop to continue reading characters in input file until end of file is reached
    	{
                fscanf(fp,"%f",x+i);	
		//putc(c,ofp);//write resulting ASCII value to ouput file
    		counter++;
		printf("%d = %f \n",i,*(x+i));
		i++;
	}

	counter = 0;
	while(counter < n)//while loop to continue reading characters in input file until end of file is reached
        {
                fscanf(fp,"%f",y+j);
                counter++;
                printf("%d = %f \n",j,*(y+j));
		j++;
        }

    	printf("\n");

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

        counter = 0;
	j=0; 
	while(counter < n)//while loop to continue reading characters in input file until end of file is reached
        {
                fprintf(ofp,"%d = %f \n",counter,*(u2+j));
                printf("%d = %f \n",counter,*(u2+j));
		counter++;
                j++;
        }
	
	fclose(fp);//close input and output files
        fclose(ofp);
}

