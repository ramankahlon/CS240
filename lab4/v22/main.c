#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
	char input[100],output[100],url[100];//array and variable declarations
	int a,b;
	for(a=0;b != '\n';a++)//for loop to put input into a character array 
    	{
        	b = getchar();
        	if(b != '\n')
                	input[a] = b;
     	}

    	int final = a;
	
	//stop at colon or slash
	
	int i;
    	for(i=0; i<final; i++)//for loop to convert chars to ints, then add value of 32 to convert to lower case, and check for '/' or ':' 
    	{
        	int b = (int)(input[i]);

        	if(b <= 90 && b >= 65)//ASCII values of 65 to 90 (A-Z)
            		b += 32;

        	url[i] = (char)(b);
	}	

	//for loop to check for correct http:// format
	int index;
	char protocol[7] = {'h','t','t','p',':','/','/'}; 
	char dname[100];
	int ret = 1;
	for(index=0;index<7;index++)
	{
		if(url[index]!=protocol[index])//set ret value to -1 if url doesn't begin with "http://"
			ret = -1;
	}

	if(ret == -1)//print statement for bad format
	{
		printf("\nThe url entered is ill-formatted.\n");	
		return -1;
	}

	int j,k=7,numericdom=1;
	for(j=0; k<final; j++,k++)//for loop to check whether domain name is IP address (numbers separated by '.') 
	{
		char c = url[k];
		if(c == '/' || c==':') 
			break;
	 	if((((int)(c) > 57) || ((int)(c) < 48)) && c!='.')
			numericdom = -1;
		dname[j] = c;	
	}

	dname[j] = '\0';
	printf("%s\n",dname);

	int address[4];
        int dlen = j;
	int l=0,m=0,n=0,y=0;
	k=0;
	char num[6];
	unsigned int result,last; 
	if(numericdom == 1)
	{
		//sscanf(dname,"%d.%d.%d.%d",);//scan user input to receive value of N
		//printf("within if:");//debugging
		for(l=0;l<4;l++)
		{
			for(k=0;m<dlen;m++,k++)
			{
				if(dname[m]=='.')
					break;
				num[k] = dname[m];
				//printf("%d = %c\n",k,num[k]);
			}
			num[k] = '\0';
	                sscanf(num,"%d",&address[l]);//scan user input to receive value of N
			//printf("1:%s\n",num);
			//printf("2:%d",address[l]);
			//total = total + (address[l] * 
			result = address[l];
			printf("\naddress[%d]: %d",l,result);
			y = result & 0x1;
			printf("\n%d, %02x\n",y,y);
                	for(n=0;n<31;n++)
			{
			        result = result >> 1;
				last = result & 0x1;
                		printf("%d, %02x\n",last,last);
        			//printf("%02x",last);
			}
			m++;
		}
		printf("\n");
		
		
	}
	
	else
	{
	 	printf("within else:");	
		char gov[4] = {'v','o','g','.'};
		char org[4] = {'g','r','o','.'};
		int count = 0;
		int govcheck = 1;
		int orgcheck = 1; 
		j--;
	
		for(;j>=0 && count<4;j--,count++)
		{
			if(dname[j]!=gov[count])
				govcheck = -1;
		}
		
		printf("%d\n",govcheck);

		for(j = dlen,count=0;j>=0 && count<4;j--,count++)
        	{
                	if(dname[j]!=org[count])
                        	orgcheck = -1;
        	}

                printf("%d\n",orgcheck);

		if(govcheck == -1 && orgcheck == -1)
                	printf("\nThe url entered is ill-formatted.\n");
	}
/*
        char out[100] = {'h','o','s','t',' '};
		
	printf("%s ",dname);

	for(l=0;l<dlen;l++)
        {
		out[l+5] = dname[l];
	}
	system(out);
	printf("\n");
*/


}

void getdomain()
{
        char input[100],output[100],url[100];//array and variable declarations
        int a,b;
        for(a=0;b != '\n';a++)//for loop to put input into a character array
        {
                b = getchar();
                if(b != '\n')
                        input[a] = b;
        }

        int final = a;

        //stop at colon or slash

        int i;
        for(i=0; i<final; i++)//for loop to convert chars to ints, then add value of 32 to convert to lowe
r case, and check for '/' or ':'
        {
                int b = (int)(input[i]);

                if(b <= 90 && b >= 65)//ASCII values of 65 to 90 (A-Z)
                        b += 32;

                url[i] = (char)(b);
        }

        //for loop to check for correct http:// format
        int index;
        char protocol[7] = {'h','t','t','p',':','/','/'};
        char dname[100];
        int ret = 1;
        for(index=0;index<7;index++)
        {
                if(url[index]!=protocol[index])//set ret value to -1 if url doesn't begin with "http://"
                        ret = -1;
        }

        if(ret == -1)//print statement for bad format
        {
                printf("\nThe url entered is ill-formatted.\n");
                return -1;
        }

        int j,k=7,numericdom=1;
        for(j=0; k<final; j++,k++)//for loop to check whether domain name is IP address (numbers separated
 by '.')
        {
                char c = url[k];
                if(c == '/' || c==':')
                        break;
                if((((int)(c) > 57) || ((int)(c) < 48)) && c!='.')
                        numericdom = -1;
                dname[j] = c;
        }

        dname[j] = '\0';
        printf("%s\n",dname);

}	
