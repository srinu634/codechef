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
	
	int t,n,k;
	int i;
	int m;	
long long int denum_mod;
long long	 int temp;
long long int result;
	scanf("%d",&t);

		for(i=0;i<t;i++) {
	scanf("%d %d",&n,&k);

if(k==1) {
if(n%2==0) 
printf("1\n");
else
printf("0\n");
continue;
}
if(n==1){ 
printf("%d\n",k);
continue;
}
m=n/2;

denum_mod=getPower(k+1,MOD-2);
result= getPower(k,2*m);

if(n%2){ 
result = ((result*k)%MOD - k )%MOD;
result = (result*denum_mod)%MOD; 
}//odd case
else
{
	result= (result+k)%MOD;
	result = (result*denum_mod)%MOD;
}//even

printf("%lld\n",result);
	}//for	
	return 0;
}//main

