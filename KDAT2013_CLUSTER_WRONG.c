#include<stdio.h>
#include<string.h>

char s[100];
char temp[1000];
char temp1[100];
char str[15][1000];

int main( ) {

int i,j,k;
int t,n;
int count;
int len1;


scanf("%d",&t);

	for(i=0;i<t;i++) {

scanf("%s",s) ;
scanf("%d",&n);
len1=strlen(s);
count=0;

for(j=0;j<len1;j++)
if( s[j]==' ' ){ 
s[j]='\0';
len1=j;
}

for(j=0;j<n;j++) {
scanf("%s",temp);	
if ( temp[0]==s[0]  && strlen(temp)>len1 ) { 

for(k=0;k<len1;k++)
temp1[k]=temp[k];
temp1[k]='\0';
if( strcmp(s,temp1) ==0) { 
//printf("YES\n");
strcpy(str[count],temp) ;
count++;
}
}

}//j :for loop

//for(j=0;j<count;j++)
//printf("(%s)",&str[j][0] );

if( count==0){ 
printf("%s\n",s);
continue;
}

strcpy(temp,str[0] );

	for(j=1;j<count;j++) 
if( strcmp ( str[j] , temp ) < 0 )
strcpy( temp, str[j]);	

printf("%s\n",temp);
}//for :j 

return 0;
}


