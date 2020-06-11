#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

void mon_chld(int sigint)
{
	int exstat;
	pid_t pid;
	//int *point;
	//*point = n;
	//printf("After declaration");	
	pid = wait(&sigint);
	printf("pid %d has been terminated.\n",getpid());
	exstat = WEXITSTATUS(sigint);	
	//printf("After exitstatus");
}

// signal handler example to catch SIGALRM:
// // useful in implementing timers in apps
//
// #include <stdio.h>
// #include <stdlib.h>
// #include <signal.h>
// #include <unistd.h>
//
// main()
// {
// int *y;
// void my_alrm_handler(int);
//
//   // register signal handler
//     if (signal(SIGALRM, my_alrm_handler) == SIG_ERR) {
//             fprintf(stderr, "signal handler registration failed\n");
//                     exit(1);
//                       }
//
//                         // set alarm, wait, then repeat ...
//                           while(1) {
//                                   alarm(3);
//                                           pause();
//                                             }
//
//                                             }
//
//
//                                             // signal handler my_alrm_handler() catches CTRL-\ key input
//
//                                             void my_alrm_handler(int sigval)
//                                             {
//
//                                               if (sigval == SIGALRM) {
//                                                       printf("ring ring!\n");
//                                                               return;
//                                                                 }
//                                                                   else
//                                                                           exit(1);
//
//                                                                           }
//
