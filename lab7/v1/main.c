// signal handler example to catch SIGSEGV

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>


main()
{
void my_segv_handler(int);
int *y;

  printf("main: %d\n", getpid());

  // register signal handler my_segv_handler() with OS
  signal(SIGSEGV, &my_segv_handler);

  *y = 5;

}


// signal handler catches segmentation fault interrupts

void my_segv_handler(int sigval)
{

  if (sigval == SIGSEGV) {
	printf("my process is accessing memory it shouldn't\n");
	printf("my_segv_handler: %d\n", getpid());
	while(1);
  }

}
