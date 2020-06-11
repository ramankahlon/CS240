#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	pid_t k;//declare and initialize variables
	int status;
	char command[50],str[50] = {'$',' ','\0'};
	int i,j;
	int a = -1, b = 0, d = 0;
	int l = -1;
	char c;
	char cprt[100] = {'c','p','r','t',' '};
	char lock[4] = {'l','c','k','\0'};
	char key[100],sec[100];
	int ch,check=-1,lck=-1;

        FILE *fp;//declare input and output files
        char input[100] = {'s','e','c','r','e','t','s','t','r','i','n','g','.','t','x','t','\0'};

        //  open file to read

        fp = fopen(input,"r");//open the input and output files

        //  open failed

        if(fp == NULL)//print error message if input file is unable to open
        {
	        fprintf(stderr,"file %s does not exist\n",input);
                exit(1);
        }
 
        while((ch = (char)(getc(fp))) != EOF)//set sec array to hold secret string from secretstring.txt
        {
                sec[b] = ch;
                b++;
        }
	
	b--;
        sec[b] = '\0';//last character becomes null
	fclose(fp);

  	while(1) 
	{
		fprintf(stdout,"%s",str);//print out shell prompt (changes based on cprt)
		for(i=0;(c=getchar())!='\n';i++)//read in command (user input)
			command[i] = c; 
        	command[i] = '\0';//set last char to null to indicate end of string
		if(command[0] == '\n')//if enter is pressed
			continue;
		else if((command[0] == 'E' || command[0] == 'e' || command[0] == 'X' || command[0] == 'x') && command[1] == '\0')//quit out if 'E','e','X',or 'x'
			break;
		for(j=0;j<5;j++)//for loop to check whether command is cprt (a=1 if true, a=-1 if false)
		{
			if(command[j] == cprt[j])
				a=1;
			else
			{
				a=-1;
				//printf("%d",2);
				break;
			}
			//printf("1: %d\n",a);
		}
                if(a == 1)//set str to new prompt entered by user
                {
                        for(j=5;command[j]!='\0';j++)
                        {
                                str[j-5] = command[j];
                        }
                        str[j-5] = ':';
                        str[j-4] = ' ';
                        str[j-3] = '\0';
                }

		else //if input is not cprt  
		{
			for(j=0;j<4;j++)//for loop to check whether command is "lck" (lock)
			{
				if(command[j] == lock[j])
					a=1;
				else
				{
					a=-1;
					break;
				}
			}
			if(a==1)//execute only if "lck" is entered
			{
				//scan for lock
				//scanf("
				while(check == -1)//execute loop to continuously check whether correct secret string is entered
				{
					fprintf(stdout,"\nkey to unlock: ");
                                	for(j=0;(c=getchar())!='\n';j++)//loop to get user input for secret string guess 
                                	{
                                        	key[j] = c;
                                	}
                                	key[j] = '\0';
					//printf("key: %s, %d",key,j);//debugging
                                        //printf("sec: %s, %d",sec,b);//debugging

					if(b == j)
					{	
						//j = 0;//debugging
						check = 1;
						for(d=0;d<b;d++)//while loop to continue reading characters in input file until end of file is reached
    						{
							if(sec[d] != key[d])//if any char in input is different from secret string, quit out, and execute while loop again
							{			
    								check = -1;
								break;
							}
							//printf("check = %d",check);//debugging
						}
					}
				}
				check = -1;//reset check to -1 for next time "lck" is entered
				//continue;//debugging
			}
			else //if command meets none of the conditions stated above
			{
				system(command);//execute command through generic Linux shell by call to system()
			}
		}
	}
}
