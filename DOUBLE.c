#include<stdio.h>
#include<string.h>
int main( ) {
unsigned long long int n;
int t;
scanf("%d",&t);
while( t>0){
scanf("%llu",&n);
if ( n %2==0 )
printf("%llu\n",n );
else if(n!=1)
printf("%llu\n",n-1);
else
printf("%d\n",0);
t--;
}
return 0;
}
