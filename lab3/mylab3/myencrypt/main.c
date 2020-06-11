#include <stdio.h>
#include <stdlib.h>

int main()
{
    int index1,index2;//variable and array declarations/initializations
    int i = 0;
    char temp;//temp variable to temporarily hold getchar() to place in n array
    char n[100];//array for N (first incremental value input from user)
    char input[100];//array for input file name
    char output[100];//array for output file name

    for(index1=0;;index1++)//for loop to read in N to an array
    {
	temp = getchar();
	if(temp == ' ')
		break;
    	n[index1] = temp;
    }
    sscanf(n,"%d",&i);//scan user input to receive value of N 

/*  printf("integer = %d\n",i);//print the value of N (debugging)
    
    int a=0;
    for(a =0; a < index1;a++)//for loop to print array (debugging) 
        printf("%c",n[a]);
*/    

    for(index1=0;;index1++)//for loop to receive input file name 
    {
	temp = getchar();
        if(temp == ' ' || temp == '\n')
                break;
        input[index1] = temp;
    }
    input[index1]='\0';//end of input array
//  printf("%s\n",input);//print input file name (debugging)
    
    for(index1=0;;index1++)//for loop to receive output file name
    {
	temp = getchar();
        if(temp == ' ' || temp == '\n')
                break;
        output[index1] = temp;
    }
    output[index1]='\0';//end of output array
//  printf("%s\n",output);//print output file name (debugging)
   
    FILE *fp,*ofp;//declare input and output files
//  int x, y, z;//variables for debugging while scanning input file and writing output file 
      
//  open file to read

    fp = fopen(input,"r");//open the input and output files
    ofp = fopen(output,"w");
	
//  open failed

    if(fp == NULL)//print error message if input file is unable to open 
    {
        fprintf(stderr,"file %s does not exist\n",input);
        exit(1);
    }

    if(ofp == NULL)//print error message if output file is unable to open 
    {
        fprintf(stderr,"file %s does not exist\n",output);
        exit(1);
    }
        
    int c;//declare variable c for original ASCII value for character in input file 
    while((c = getc(fp)) != EOF)//while loop to continue reading characters in input file until end of file is reached 
    {
	c = (c + i)%128;//add incremental value and modulus by 128 to get valid ASCII value within range 
	if(c < 0)//if statement to check whether resultant value after encrypting is negative
		c += 128;//incrementation for wrap-around when resulting number is negative
		putc(c,ofp);//write resulting ASCII value to ouput file  
    }

    printf("\n");

    fclose(fp);//close input and output files
    fclose(ofp);
    /* fscanf(fp,"%d %d %d",&x,&y,&z);
       fprintf(stdout,"%d %d %d\n",x,y,z);
    */
}
