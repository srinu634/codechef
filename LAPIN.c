#include<stdio.h>
#include<string.h>

int fre1[26];
int fre2[26];

int main ( ) { 
int t;
int i,j;
int left,right;
int len;
int flag;

char str[1005];
scanf("%d",&t);

while(t--) { 
scanf("%s",str);
flag=1;
for(i=0;i<26;i++)
{
fre1[i]=0;
fre2[i]=0;
}

len=strlen(str);

left=0;
right = (len+1)/2;

i=left;
for(;i < len/2;i++)
fre1[ str[i] - 'a' ] ++;

for( i= right;i<len;i++)
fre2 [ str[i] - 'a']++;

for(i=0;i<26;i++) 
if ( fre1[i]!=fre2[i] ) { 
	flag=0;
	printf("NO\n");
	break;
}
if( flag )
printf("YES\n");

} //test cases



return 0;
}//main
