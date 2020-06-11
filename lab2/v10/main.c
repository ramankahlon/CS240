/*
// Basic string processing.

#include <stdio.h>

int main()
{
int i;
char a[6]; 

  a[0] = 'a';
  a[1] = 'b';
  a[2] = '\0';
  a[3] = 'd';
  a[4] = 'e';
  a[5] = '\0';

  printf("%s\n",a);
}
*/

// Basic string processing.

#include <stdio.h>
#include <string.h>

char *strcpy(char *dest, const char *src);

int main()
{
  char a[6];
  strcpy(a,"abcdef");
  printf("%s\n",a);
}

