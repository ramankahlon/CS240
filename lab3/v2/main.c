// scope of global vs. local variables with conflicting names

#include <stdio.h>

void mysub(void);

int x;

int main()
{

  x = 5;
  printf("%d\n",x);

  mysub();

}


void mysub(void)
{
int x;

  printf("%d\n",x);

}
