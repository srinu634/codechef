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

ll q,n,m,mat[400][400];

int main() {
    ll i,j;

    cin>>n>>m;

    q= 0;

    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            cin>>mat[i][j];

    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            if(mat[i][j] == 1)
                q++;
    cout<<q<<endl;

    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            if(mat[i][j] == 1)
                cout<<i+1<<" "<<j+1<<" "<<i+1<<" "<<j+1<<endl;



return 0;
}
