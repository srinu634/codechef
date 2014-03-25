#include<stdio.h>

int n[1000];

int main( ) {
int t,l;
int i,j;//iterators
int result;

scanf("%d",&t);
while(t--) {
scanf("%d",&l);//length
for(i=0;i<l;i++)
scanf("%d",&n[i]);
if(l==1){
printf("%d\n",n[i]);
continue;
}
result= gcd(n[0],n[1] );
for(i=2;i<=l-1;i++)
result = gcd(result,n[i]);

printf("%d\n",result);
}//		
	return 0;
}//main

int gcd (int a,int b) {
int t;
while (b!=0)
{
	t=b;
	b=a%t;
	a=t;
}
return a;
}//gcd
