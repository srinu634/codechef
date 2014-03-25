#include<stdio.h>
#define MAX 10001

int n[MAX];
int temp[MAX];
int prime[2000];

		int main( ) {
int t,nmbr;
int  i,j,k;//iterators
int count;

for(i=1;i<MAX;i++)
temp[i]=i;

count=0;
temp[1]=0;//1 is not a prime.
temp[0]=0;

for(i=2;i<MAX;i++) {
for(j=i;j<MAX;) {
if( j+i >=MAX)
break;
temp[j+i]=0;
j=j+i;
}//j loop
}//i loop

for(i=2;i<MAX;i++)
if(temp[i]!=0)
	prime[count++]=temp[i];

for(i=0;i<MAX;i++)
n[i]=0;

for(i=0;i<count;i++){ 
for(j=0;j<count;j++){
if ( (prime[i] + 2*prime[j]) <=10000 ) {
n[(prime[i] + 2*prime[j])]++;
}
}//j loop 
}//i loop


scanf("%d",&t);
for(i=0;i<t;i++) {
scanf("%d",&nmbr);
printf("%d\n",n[nmbr] );

}//for

return 0;
}//main
