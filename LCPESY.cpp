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

ll f1[260],f2[260];

int main() {
ll t,i,j,n,l1,l2;
char s1[100000],s2[100000];

cin>>t;

while(t--){

    cin>>s1>>s2;

    l1 = strlen(s1);
    l2 = strlen(s2);
    for(i=0;i<260;i++){ f1[i] = 0; f2[i]=0;}

    for(i=0;i<l1;i++)
            f1[ s1[i] ]++;

    for(i=0;i<l2;i++)
            f2[s2[i] ]++;

    ll ans;
    ans = 0;

    for(i=0;i<260;i++)

        ans += min(f1[i],f2[i]);

    cout<<ans<<endl;


}

return 0;
}
