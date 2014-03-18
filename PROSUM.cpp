#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
typedef long long int ll;

ll max(ll a,ll b){
    return a>b?a:b;
}

int main(){

    ll n,t,a,res,i,k,j;

   scanf("%lld",&t);// cin>>t;

    while(t--){

       scanf("%lld",&n);//  cin>>n;

        res = n*(n-1);res /= 2;
        k = 0;j=0;

        for(i=0;i<n;i++){
          scanf("%lld",&a);//  cin>>a;
            if( a == 0 || a == 1)
                j++;
            if( a == 2)
                k++;
        }
//cout<<j<<" "<<k<<endl;

res = res -    (( j*(j-1) ) / 2);
res =  res -   (( k*(k-1) ) / 2);
res = res - (j*(n-j));

    cout<<res<<endl;

    }

return 0;
}
