/* Srinivas Suri- Bits Pilani Hyderabad */


#include<stdio.h>
#define MAX 100000

int prime[MAX+1];
int n[MAX+1];
int primecount; //number of prime numbers till 10^5
int dp[MAX+1];



void generatePrime()  {         // Sieve of Eratosthenes
int i,j; //iterators
primecount=0;

for(i=0;i<MAX+1;i++)
n[i]=i;

for(i=2;i<MAX+1;i++)     
	if( n[i]!=0 ) 
		for(j=2*n[i];j<MAX+1;j+=n[i])
			n[j]=0;

for(i=2;i<MAX+1;i++)			
	if(n[i] != 0)
		prime[primecount++]=n[i];	
}

dpAnswer( ) { 
int i,j;

for(i=0;i<MAX+1;i++)   //Initialising to zero.
	dp[i]=0;
	
for(i=0;i<primecount;i++)
	for(j = prime[i] ; j <= MAX; j+=prime[i] )
		dp[j]++; 	
				
}

int main( ) { 
int i,j; //iterators
int t; //test case
int a,b,k;
int answer;

generatePrime();
dpAnswer( ); // Store the no.of prime factors for each number in another array.  

scanf("%d",&t);

while(t--) {
	scanf("%d %d %d",&a,&b,&k);
	
	answer=0;
	
	for(i=a;i<=b;i++)
		if ( dp[i] == k)
			answer++;
			
	printf("%d\n",answer); 		
}


return 0;
}//main
