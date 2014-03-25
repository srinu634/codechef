#include<stdio.h>

int main( ) {
	int t;
	double p,m,profit;
	
	scanf("%d",&t);
	m=10000;
	while(t--) { 
	scanf("%lf",&p);
			
	if( p >.5 ) {
	printf("%lf\n",  m+  (2*p-1) * ( (1-p)*m )); 
	continue;
	}
	
	else if (p<=.5 ){
	
	printf("%lf\n", m+(1-2*p)* ( p*m ) );
	
	}
	
	
	}//while
	
	
	
	
	
	
	
	
	return 0;
}//main
