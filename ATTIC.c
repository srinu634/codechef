/*    Srinivas Suri. Bits-Hyderabad! */

#include<stdio.h>
#include<string.h>

char str[1000000+10];

int main( ) { 
int t;
int i,j;
long long int days;
int max;
int len;
int count;

scanf("%d",&t);

while(t--) { 
max=0;
days=0;
scanf("%s",str);
len= strlen(str);
count=0;

for(i=0;i<len;i++) { 
	if (str[i]=='.')
	{ 
		count=1; 
		while(i<( len-1 ) )
		{
			if( str[i+1] != '.' )
				break;
			
			count++;
			i++;
		}
	}
	
	if( count>max)
		{ 
			max=count;
			days++;
		}	
	}

printf("%lld\n",days);


}//t


//return 0;
}
