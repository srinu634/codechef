#include<stdio.h>
#include<string.h>
#define MOD 10000009

char str[1000000];
	
int main( ) {
unsigned long long int result;
int count;
int t,i,j,len;
int flag;

scanf("%d",&t);

for(i=0;i<t;i++){
scanf("%s",str);
result=0;
len = strlen(str);
flag=0;
if(len==1)
if( str[0] == '?' ) {
printf("26\n");
continue;
}
else
{
	printf("1\n");
	continue;
} //base case

result=1;
for(j=0;j<len/2;j++){
	
if( str[j]=='?' && str[len-j-1]!='?')
continue;
else if(str[j]!='?' && str[len-j-1]=='?')
continue;
else if ( str[j]=='?' && str[len-1-j]=='?' )
result = (result*26)%MOD;
else if (str[j]==str[len-j-1])
continue;
else{
printf("0\n");
flag=1;
break;
}

}//inner for

if(len%2==1 )
if ( str[len/2]=='?' )
result = (result*26)%MOD;

if(flag==0)
printf("%llu\n",result);
}//outer for



return 0;
}//main
