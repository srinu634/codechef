#include<stdio.h>

long long int dp[10001][61];
int a[61],n;

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


long long int power(int a,int b) { 
long long int result;

if( b==0)
return 1;
if( b==1)
return a;

result = power(a,b/2);
if( b%2==1) 
return result*result*a;
return result*result;
}//power

long long int calc_ans(int curr_gcd,int pos) {	
long long int result;
int nextgcd;
if (pos==n ) {
if ( curr_gcd==1)
return 1;
return 0;
}
if ( curr_gcd==1) {  
dp[curr_gcd][pos] = power(2,n-pos);
return dp[curr_gcd][pos];
}


if ( dp[curr_gcd][pos]!=-1)
return dp[curr_gcd][pos];

dp[curr_gcd][pos+1]  = calc_ans(curr_gcd,pos+1);//excluding a[pos+1]
nextgcd = gcd(curr_gcd,a[pos] );
dp[nextgcd][pos+1] = calc_ans(nextgcd,pos+1); //including a[pos+1]
dp[curr_gcd][pos]=dp[curr_gcd][pos+1] + dp[nextgcd][pos+1];
return   dp[curr_gcd][pos] ;
}//calc_ans

	
int main( ) {
int t;
int i,j;//iterators
long long int ans;

scanf("%d",&t);

while(t--) {
scanf("%d",&n);
ans=0;
for(i=0;i<n;i++)
scanf("%d",&a[i]);

for(i=0;i<10001;i++)
for(j=0;j<61;j++)
dp[i][j]=-1;

for(i=0;i<=n-1;i++)  
ans += calc_ans(a[i],i+1 ) ;  //including a[i] 

printf("%lld\n",ans);

}//t
	return 0;
}//main
