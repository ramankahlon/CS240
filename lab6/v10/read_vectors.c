#include <stdio.h>
#include <stdlib.h>

int MAXSIZE;

int read_vectors(int *n, float **a , float **b)
{
	int i=0,j=0;//index variables for indices of two vectors a and b
    	//float x[MAXSIZE],y[MAXSIZE];
    	//printf("Enter N: ");//prompt user to enter vector size
    	//scanf("%d",n);

        FILE *fp;//declare input file
        //  int x, y, z;//variables for debugging while scanning input file and writing output file

        //  open file to read

        fp = fopen("vecin.dat","r");//open the input file

	//printf("after file is opened\n");//debugging

        //  open failed

        if(fp == NULL)//print error message if input file is unable to open
        {
                fprintf(stderr,"file %s does not exist\n","vecin.dat");
                return -1;
        }

	//printf("before fscanf\n");//debugging
        fscanf(fp,"%d",n);
        *a = malloc(sizeof(float)*(*n));//allocate memory for a and b based on n (size of each vector)
        *b = malloc(sizeof(float)*(*n));
	//printf("%d\n",*n);//debugging 

        int counter = 0;
        int c;//declare variable c for original ASCII value for character in input file
        while(counter < *n)//while loop to continue reading characters in input file until end of file is reached
        {
                fscanf(fp,"%f",*a+i);
                //putc(c,ofp);//write resulting ASCII value to output file
                counter++;
                //printf("%d = %f \n",i,*(*a+i));//debugging
                i++;
        }

        counter = 0;
        while(counter < *n)//while loop to continue reading characters in input file until end of file is reached
        {
                fscanf(fp,"%f",*b+j);
                counter++;
                //printf("%d = %f \n",j,*(*b+j));//debugging
                j++;
        }

        fclose(fp);//close input and output files

        //printf("after fclose\n");//debugging

	return 1;//file has been successfully read 
}
