#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{
	printf("Size of char = %ld\n",sizeof(char));
	printf("Size of int = %ld\n",sizeof(int));
	printf("Size of float = %ld\n",sizeof(float));
	printf("Size of double = %ld\n",sizeof(double));

	printf("Size of signed char = %ld\n",sizeof(signed char));
	printf("Size of unsigned char = %ld\n",sizeof(unsigned char));
	
	printf("Size of signed int = %ld\n",sizeof(signed int ));
	printf("Size of unsigned int = %ld\n",sizeof(unsigned int));
	printf("Size of short int = %ld\n",sizeof(short int));
	printf("Size of signed short int = %ld\n", sizeof(signed short int));
	printf("Size of unsigned short int = %ld\n", sizeof(unsigned short int));
	printf("Size of signed long int = %ld\n", sizeof(signed long int));
	printf("Size of unsigned long int = %ld\n", sizeof(unsigned long int));

	printf("Size of unsigned int = %ld\n",sizeof(unsigned int));
	printf("Size of long int = %ld\n",sizeof(long int));
	printf("Size of long double = %ld\n",sizeof(long double));
}
