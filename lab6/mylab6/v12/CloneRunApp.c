#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int CloneRunApp(char *binary) 
{
	char *s[10];//declare and initialize variables
        int j=0;
	pid_t k;
        //printf("command=%s\n",binary);//debugging
        char *token;
        token = strtok(binary," ");//convert binary command into series of tokens
        
	while( token != NULL )
        {
		s[j] = token;//put token into string s
                //printf( " %s\n", token );//debugging
                token = strtok(NULL, " ");
                j++;
        }
       
	s[j] = NULL;//set last element of string to null
                                
	k = fork();//call fork to spawn a child

        //printf("fork = %d",k);//debugging

        if (k==0)//if in child process
        {
       		//printf("in fork: %d",2);//debugging
                //fprintf(stdout,"new process will run: %s\n",s[0]);//print out which new process will run
                if(execvp(s[0],s)==-1)
			exit(1);//run requested command
                exit(0);//terminate child process
        }
	
	else if(k<0)//if fork fails
		return (-1);
        else //if in parent process
                return k;//wait for child process to end, then run parent process
}
