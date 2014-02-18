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
#define MAX 1000008
#define INF 100000000
typedef  int ll;
using namespace std;

struct node{
ll p;
ll t;
}a[MAX];

struct node1{
ll min;
ll max;
}t[MAX];

ll n,k,flag[MAX];

int cmpfun(const void *p, const void *q)
{
struct node * a = ((struct node *)p);
struct node * b = ((struct node *)q);
return (a->t - b->t);
}

ll compareints (const void * q, const void * w)
{
struct node * y = ((struct node *)q);
struct node * u = ((struct node *)w);
return (y->t - u->t);
}

ll search(ll nmbr,ll low,ll high){
    ll mid;
    mid  = (low+high)/2;

    if(low==high){
        if(a[low].t == nmbr)
            return low;
        else
            return -1;
    }

    if(a[mid].t<nmbr)
        return search(nmbr,mid+1,high);
    else if(a[mid].t == nmbr)
        return mid;
    else
        return search(nmbr,low,mid);

}

int main() {
    ll i,j,ans;
    cin>>n>>k;

    ans = INF;

    for(i=0;i<MAX;i++){
        t[i].min = INF;
        t[i].max = -1;
    }

    for(i=0;i<n;i++){
        cin>>a[i].t;
        a[i].p = i + 1;
        t[ a[i].t ].min = min( t[a[i].t ].min, a[i].p );
        t[ a[i].t ].max = max( t[a[i].t ].max, a[i].p );
    }


    qsort(a,n,sizeof(a[0]),cmpfun);


    for(i=0;i<n;i++){
        int val;
        val = k - a[i].t;
        ll index = search(val,0,n-1);
        if(index == -1)
            continue;

            ll l1,r1,l2,r2;
            l1 = t[ a[i].t ].min; r1 = t[a[i].t].max;
            l2 = t[ a[index].t ].min; r2 = t[a[index].t].max;
            if(l1==l2)continue;

    l1 = min(l1,n+1-r1); l2 = min(l2,n+1-r2);
    l1 = max(l1,l2);

    ans = min(ans,l1);


}
if(ans != INF)
    cout<<ans<<endl;
else
    cout<<"-1"<<endl;
return 0;
}
