#include<iostream>
#include<cmath>
#include<cstdio>
#include<vector>
#include <cstdlib>
#include<string>
#include<algorithm>
#include<cstring>
#define true 1
#define false 0
#define MAX 500
#define mod 1000000007
#define rep(i,n) for(i=0;i<n;i++)
typedef long long ll;
using namespace std;

ll fact[MAX] , revfact[MAX] ,ncr[MAX][MAX] , n ,a[MAX] ,fre[MAX];

ll fastexp(ll a,ll b) {
ll result;
if(b==0) return 1;
if(b==1) return a;
result= fastexp(a,b/2)%mod;
if( b%2==0) return ( result*result ) %mod;
return (((result*result)%mod)*a)%mod ;
}  //fastexp

void init(){
    ll i,j,nmbr;

    fact[0] = 1;
    nmbr = 500;

    //FACT
    rep(i,nmbr)
        if(i==0)continue;
        else    fact[i] = (i*fact[i-1])%mod;
    //*FACT

    rep(i,nmbr)
        revfact[i] = fastexp(fact[i],mod-2)%mod;

    //NCR
    rep(i,nmbr)
        rep(j,nmbr)
            ncr[i][j]=0;

    for(i=1;i<=nmbr;i++)
        ncr[i][1]=i, ncr[i][0]=1;

    for(i=2;i<=nmbr;i++)
        for(j=2;j<=nmbr;j++)
            ncr[i][j]= (ncr[i-1][j-1]+ncr[i-1][j] )%mod;
    //*NCR
}

int main() {
    ll n,k,t,count,i,j;

    cin>>t;

    while(t--){
        cin>>n>>k;

        rep(i,n)
            cin>>a[i] , fre[i] = 0;

        sort(a,a+n);
        count = 0;

        fre[count]++;

        for(i=1;i<n;i++)
            if(a[i] == a[i-1])
                fre[count]++;
            else
                count++ , fre[count]++;
        ++count; // 1 BASED COUNT

        if(k==0)
            cout<<"0" , continue;



    }
return 0;
}

