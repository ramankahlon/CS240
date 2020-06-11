#include <stdio.h>

int MAXSIZE;

int read_vectors(int *n, float *a , float *b)
{
	int i=0,j=0,k,l;
    	//float x[MAXSIZE],y[MAXSIZE];
    	//printf("Enter N: ");//prompt user to enter vector size
    	//scanf("%d",n);
	//m = malloc(sizeof(float)*n);
	//float x[*m],y[*m];

        FILE *fp,*ofp;//declare input and output files
        //  int x, y, z;//variables for debugging while scanning input file and writing output file

        //  open file to read

        fp = fopen("vecin.dat","r");//open the input and output files
        ofp = fopen("vecout.dat","w");

        //  open failed

        if(fp == NULL)//print error message if input file is unable to open
        {
                fprintf(stderr,"file %s does not exist\n","vecin.dat");
                return -1;
        }

        if(ofp == NULL)//print error message if output file is unable to open
        {
                fprintf(stderr,"file %s does not exist\n","vecout.dat");
                return -1;
        }

        fscanf(fp,"%d",n);

        int counter = 0;
        int c;//declare variable c for original ASCII value for character in input file
        while(counter < *n)//while loop to continue reading characters in input file until end of file is reached
        {
                fscanf(fp,"%f",a+i);
                //putc(c,ofp);//write resulting ASCII value to ouput file
                counter++;
                printf("%d = %f \n",i,*(a+i));
                i++;
        }

        counter = 0;
        while(counter < *n)//while loop to continue reading characters in input file until end of file is reached
        {
                fscanf(fp,"%f",b+j);
                counter++;
                printf("%d = %f \n",j,*(b+j));
                j++;
        }

        printf("\n");

        fclose(fp);//close input and output files
        fclose(ofp);

	return 1;
}
