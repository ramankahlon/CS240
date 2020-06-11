#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int CloneRunApp(char *);

int main()
{
	pid_t k;//declare and initialize variables
	int status;
	char command[50],str[50] = {'$',' ','\0'};
	int i,j;
	int a = -1, b = 0, d = 0;
	int l = -1;
	int size = 0;
	char c;
	char cprt[100] = {'c','p','r','t',' '};
	char lock[4] = {'l','c','k','\0'};
	char length[4] = {'l','e','n',' '};
	char grade[5] = {'g','r','a','d','e'};
	char key[100],sec[100];
	char* s[10]; 
	int ch,check=-1,lck=-1;
	char buf[100];
	int len,lt;

        FILE *fp;//declare inputt file
        char input[100] = {'s','e','c','r','e','t','s','t','r','i','n','g','.','t','x','t','\0'};

        //  open file to read

        fp = fopen(input,"r");//open the input file

        //  open failed

        if(fp == NULL)//print error message if input file is unable to open
        {
      		fprintf(stderr,"file %s does not exist\n",input);
                exit(1);
        }
        
	while((ch = (char)(getc(fp))) != EOF)//put characters from file into secret array sec
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

		else if(a == -1)//if input is not cprt  
		{
			for(j=0;j<4;j++)//for loop to check whether command is "lck" (lock), "len " (length), or "grade"
			{
				if(command[j] == lock[j])
					a=1;
				else
				{
					if(command[j] == length[j])
						a=2;
					else
					{
						if(command[j] == grade[j])
							a=3;
						else
						{
							a=-1;
							break;
						}
					}
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
			else if(a==2)//execute only if "len" is entered
			{
				j = 4;//set index to start at 4 (after "len ") to keep track of total input length
				while(command[j]!='\0')//loop to increment input length
					j++;
				printf("length of entry: %d\n",j-4);//print out j-4 (length of string following "len ")
			}
			else if(a==3)//execute only if "grade" is entered
			{
				system("xdg-open /u/data/u3/park/pub/cs240/grades/kahlonr/");//open grades in command line  
			}
			else //if command meets none of the conditions above
                        {
				//printf("works: \n");//debugging
                                //fgets(buf, 100, stdin);//debugging
                                //printf("works 2\n");//debugging
				if(strlen(command) == 0)//if length of command is 0, then skip the system call
                                	continue;
		/*		int j=0;
				//printf("command=%s\n",command);//debugging
				char *token;
				token = strtok(command," ");
				while( token != NULL ) 
   				{
					s[j] = token;
      					//printf( " %s\n", token );//debugging
      					token = strtok(NULL, " ");
   					j++;
				}
				s[j] = NULL; 
		*/
                                //buf[len-1] = '\0';//debugging

				//printf("after loop: %d\n",1);//debugging
				//printf("%s",command);//debugging

	                        k = CloneRunApp(command);//call fork to spawn a child
	
				//printf("clonerunapp ret = %d",k);//debugging
        			/*
	                        if (k==0)//if in child process
                                {
                                        //printf("in fork: %d",2);//debugging
					fprintf(stdout,"new process will run: %s\n",s[0]);//print out which new process will run
                                        execvp(s[0],s);//run requested command
					exit(0);//terminate child process
				}
				else //if in parent process
					waitpid(k,NULL,0);//wait for child process to end, then run parent process
				*/
			}
		}
	}
}

