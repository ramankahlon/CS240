#include <stdio.h>

int main()
{
    char input[100],output[100];//array and variable declarations
    int a;
    int b = 0;
    int index;
    
    for(a=0;b != '\n';a++)//for loop to put input into a character array 
    {	
	b = getchar();
	if(b != '\n')
		input[a] = b;
     }	   
    
    int final = a;
   
   /* 
    for(index =0; index < final-1;index++)//print out input string (debugging)
        printf("%c",input[index]);
    
    printf("\n");
   */
    int i;
    for(i=0; i<final; i++)//for loop to convert chars to ints, then add/subtract values of 17 and 32 to convert lower/upper case, numbers, and other characters 
    {
        int b = (int)(input[i]);
        
        if(b <= 90 && b >= 65)//ASCII values of 65 to 90 (A-Z)
            b += 32;
        else if(b <= 122 && b >= 97)//ASCII values of 97 to 122 (a-z)
            b -= 32;
        else if(b <= 57 && b >= 48)//ASCII values of 48 to 57 (1-9)
            b += 17;
        else
            b = 32;//if character is a space
        
        input[i] = (char)(b);
    }
    
    for(index =0; index < final;index++)//for loop to print out resultant string (array of chars) 
        printf("%c",input[index]);

    printf("\n");
 
}
