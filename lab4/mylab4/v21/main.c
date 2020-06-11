include <stdio.h>

int main()
{
	unsigned int i,y,result,last,j,k;
	scanf("%u",&i);//largest value stored in unsigned int = 2147483647
	//printf("%u",i);//print out user input (debugging)
        y = i & 0xF;
	
	result = i;
	
	j = 1 << (sizeof(i)*8-1);
	while(j>0)//for loop to print 0 or 1 to convert input to binary
	{
		if(i & j)
			printf("1");
		else
			printf("0");
		j >>= 1;
	}

	printf("\n%u, %02x\n",y,y);

	for(k = 0;k<7;k++)
	{
		result = result >> 4;
		last = result & 0xF;
		printf("%d, %02x\n",last,last); 
	}
}
