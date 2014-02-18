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
typedef long long int ll;
using namespace std;

ll dp[100][100],a[100],n,k,q;


void preprocess() {
    ll i,j,row,col;

    for(i=0;i<n;i++)
        for(j=i;j<n;j++)
            if(i==j)
                dp[i][j] = a[i];
            else
                dp[i][j] = min(a[j],dp[i][j-1]);

}

ll solve(ll k) {
    ll i,j,count;

    count = 0;

    for(i=0;i<n;i++)
        for(j=i;j<n;j++)
            if(dp[i][j] == k)
                count++;
return count;
}

int main() {
ll i,j;

cin>>n;


    for(i=0;i<n;i++)
        cin>>a[i];

    preprocess();

    cin>>q;
    while(q--){
        cin>>k;
        cout<<solve(k)<<endl;
    }


return 0;
}
