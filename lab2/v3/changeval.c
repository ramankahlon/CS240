#include <stdio.h>

void changeval(int *a)
{
  printf("%p\n",a);
  *a = 3;
}

