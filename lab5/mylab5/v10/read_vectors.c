#include <stdio.h>

int MAXSIZE;

int read_vectors(int *n, float *a , float *b)
{
    int i,j,k,l;
    int vecsize=0;
    float x[MAXSIZE],y[MAXSIZE];
    int ret = 0;
    //ret = 0;
    printf("Enter N: ");//prompt user to enter vector size
    scanf("%d",n);
    //printf("%d",*n);(debugging)
    if(*n<=0 || *n>MAXSIZE)//return -1 if vector size entered is less than or equal to 0 or greater than 50  
         return -1;
    printf("Enter 1st array: ");
    for(i=0;i<*n;i++)//for loop to store first vector
    {
        scanf("%f",a+i);
        //printf("%d= %f",i,*(a+i));//print statement to restate array values (debugging)
    }
    printf("Enter 2nd array: ");//for loop to store second vector
    for(j=0;j<*n;j++)
    {
        scanf("%f",b+j);
        //printf("%d= %f",j,*(b+j));//print statement to restate array values (debugging) 
    }
    return 0;
}
