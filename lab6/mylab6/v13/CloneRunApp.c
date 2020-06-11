#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int CloneRunApp(char *binary) 
{
	char *s[10];//declare and initialize variables
        char *str;
	char t[100];
	int j=0;
	pid_t k;
        //printf("command=%s\n",binary);//debugging
        char *token;
	char char1,char2;
	int sleeptime = 0;

        token = strtok(binary," ");//convert binary command into series of tokens
        
	while( token != NULL )
        {
		if(j==0 && token[0]=='d' && token[1]=='d')//if command begins with dd
			strcpy(t,token);//put token into string t 
		else
		{
			s[j] = token;//put token into string s
			//printf( " %s\n", token );//debugging
			//printf( " %s\n", s[j] );//debugging
			j++;//increment index variable j
		}
		token = strtok(NULL, " ");
	}
      
	//str = s[0]; 
	s[j] = NULL;//set last element of array to null
	//t[j] = NULL;
        
	if(t[0]=='d' && t[1]=='d')
	{
		sscanf(&t[2],"%d",&sleeptime);//scan number after "dd" into sleeptime variable
	}
        
	//printf("sleeptime = %d\n",sleeptime);//debugging
 
	k = fork();//call fork to spawn a child

        //printf("fork = %d\n",k);//debugging

        if (k==0)//if in child process
        {
       		//printf("in fork: %d\n",2);//debugging
                fprintf(stdout,"new process will run: %s\n",s[0]);//print out which new process will run
                if(sleeptime != 0)
		{
			sleep(sleeptime);
			//printf("after sleep\n");//debugging
		}
		if(execvp(s[0],s)==-1)
			exit(1);//run requested command
                exit(0);//terminate child process
        }
	
	else if(k<0)//if fork fails
		return (-1);
        else //if in parent process
                return k;//wait for child process to end, then run parent process
}
