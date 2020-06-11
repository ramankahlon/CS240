#include <unistd.h>
#include <sys/wait.h>

void mon_chld(int status)
{
	int exstat;
	pid_t pid;
	//int *point;
	//*point = n;
	
	pid = wait(&status);
	exstat = WEXITSTATUS(status);	
}
