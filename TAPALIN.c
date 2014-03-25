#include<stdio.h>
#define MOD 1000000007

long long int getPower(int a,int b) {
long long int result;
if(b==0)
return 1;
if(b==1)
return a;
result= getPower(a,b/2)%MOD;
if( b%2==0)
return ( result*result ) %MOD;
return     (((result*result)%MOD)*a)%MOD ;
}//getPower
	
	int main( ) {
int t;
int n;
int i;
long long int denum_mod;
unsigned long long int result;
scanf("%d",&t);
denum_mod= getPower(25,MOD-2);
	for(i=0;i<t;i++) {
scanf("%d",&n);
	if(n==1) {
printf("%d\n",26);
continue;
}
result = getPower(26,n/2)%MOD;
result = result-1;
if(n%2==0){ 
result = (52*result)%MOD;
result = (result*denum_mod) %MOD;
}
else
{
result = (result *52   + 25*getPower(26,n/2+1) )%MOD; 	
result = (result*denum_mod)%MOD;
}//else
printf("%llu\n",result );
}//for
return 0;
}//main
