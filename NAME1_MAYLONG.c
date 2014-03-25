#include<stdio.h>
#include<string.h>
 
char child[200000];
char parent_a[200000];
char parent_b[200000];
long int count_parent[26];
 
 
int main( ) {
int t,i,j,k,n,len,flag;
 
scanf("%d",&t);
 
for(i=0;i<t;i++) {
flag=1;
for(j=0;j<26;j++) 
count_parent[j]=0;
 
scanf("%s %s",parent_a,parent_b);
scanf("%d",&n);
 
len=strlen(parent_a);
for(j=0;j<len;j++)
count_parent[ parent_a[j]-'a' ]++;
 
len=strlen(parent_b);
for(j=0;j<len;j++)
count_parent[ parent_b[j]-'a' ]++;
 
for(j=0;j<n;j++) {
scanf("%s",child);
len=strlen(child);
for(k=0;k<len;k++)
	count_parent[  child[k]-'a' ]--;
}//n

for(j=0;j<26;j++) 
if ( count_parent[j] < 0 ) { 
flag=0;
break;
}


if(flag==1)
printf("YES\n");
else
printf("NO\n");
 
}//t
 
return 0;
}//main
 

