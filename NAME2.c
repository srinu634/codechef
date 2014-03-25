#include<stdio.h>
#include<string.h>

char m[30000];
char w[30000];
char temp[30000];
char sub[30000];

int main( ) {

int i,j,k,len1,len2,flag,t,index;
int count;

scanf("%d",&t);

for(i=0;i<t;i++) {

count=0;
scanf("%s %s",m,w);
len1=strlen(m);
len2=strlen(w);

if(len1>len2) {
strcpy(temp,m);
strcpy(m,w);
strcpy(w,temp);
len1=strlen(m);
len2=strlen(w);
}

k=0;
for(j=0;j<len1;j++)
{	
	while( w[k]!='\0'  && w[k]!=m[j]) 
	k++;
	if(!w[k])
	break;
	if( w[k] ) 
	sub[count++]=w[k];
	k++;
}//for

sub[count]='\0';

//printf("(%s)",sub);
if ( strcmp(sub,m) == 0)
{
	printf("YES\n");
	continue;
}

if ( strcmp(sub,w) == 0)
{
	printf("YES\n");
	continue;
}


printf("NO\n");
}//for


return 0;
}//main
