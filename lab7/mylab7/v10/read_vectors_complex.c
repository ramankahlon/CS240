#include <stdio.h>
#include <stdlib.h>
#include "read_vectors_complex.h"

int MAXSIZE;

int read_vectors_complex(int *n, complex_num_t **a, complex_num_t **b, char **argv)
{
	int i=0,j=0;//index variables for indices of two vectors a and b

	FILE *fp1,*fp2;//declare input file
        //  int x, y, z;//variables for debugging while scanning input file and writing output file

        //  open file to read

	//printf("file 1 = %s\n",argv[2]);//debugging
	//printf("file 2 = %s\n",argv[3]);//debugging
        fp1 = fopen(argv[2],"r");//open the 2 input files containing the 2 vectors
	fp2 = fopen(argv[3],"r");

	//printf("after file is opened\n");//debugging

        //  open failed

        if(fp1 == NULL)//print error message if first input file is unable to open
        {
                fprintf(stderr,"file %s does not exist\n",argv[2]);
                return -1;
        }

	if(fp2 == NULL)//print error message if second input file is unable to open
	{
                fprintf(stderr,"file %s does not exist\n",argv[3]);
                return -1;
        }

	//printf("before fscanf\n");//debugging
        //fscanf(fp1,"%d",n);
	/*printf("Enter vector dimension: ");
	scanf("%d",n);
        printf("\nvector dimension = %d\n",*n);
	*/
	//complex_num_t a[(*n)*2];

	sscanf(argv[1],"%d",n);//set 2nd argument of command line to n (vector dimension) 
        //printf("\nvector dimension = %d\n",*n);//debugging

	*a = calloc(sizeof(complex_num_t),*n);//allocate memory for a and b based on n (size of each vector)
        *b = calloc(sizeof(complex_num_t),*n);
	//printf("%d\n",*n);//debugging 

	int counter = 0;
        //int c;//declare variable c for original ASCII value for character in input file
        while(counter < *n)//while loop to continue reading numbers from vector in first input file until end of file is reached
        {
                fscanf(fp1,"%f",&((*a)[i].x));
		fscanf(fp1,"%f",&((*a)[i].y));
                counter++;
                //printf("%d = %f,%f\n",i,(*a)[i].x,(*a)[i].y);//debugging
                i++;
        }

	i = 0;//reset i and counter
        counter = 0;
        
	while(counter < *n)//while loop to continue reading numbers from vector in second input file until end of file is reached
        {
                fscanf(fp2,"%f",&((*b)[i].x));
		fscanf(fp2,"%f",&((*b)[i].y));
                counter++;
                //printf("%d = %f,%f\n",i,(*b)[i].x,(*b)[i].y);//debugging
                i++;
        }
	
	fclose(fp1);//close input and output files
	fclose(fp2);

        //printf("after fclose\n");//debugging

	return 1;//file has been successfully read 
}
