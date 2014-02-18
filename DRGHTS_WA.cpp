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
#define MAX 100000
typedef long long int ll;
using namespace std;

ll n,f,r,m,size[MAX];

struct node {
ll id;
ll w;
} a[MAX];

ll get(ll i)
{
    if (a[i].id == i)
        return i;
    a[i].id = get( a[i].id );
 return a[i].id;
}

void merge(ll x, ll y)
{
    ll xset = get( x);
    ll yset = get( y);
    a[xset].id = yset;
}

int cmpfun(const void *p, const void *q)
{
struct node * a = ((struct node *)p);
struct node * b = ((struct node *)q);
return (a->id - b->id);
}

int main() {
    ll i,j,c,d,prev,curr;

    cin>>n>>m;

    for(i=0;i<n;i++){
        a[i].id = i;
        size[i] = 1;
    }

    for(i=0;i<n;i++)
        cin>>a[i].w;


    for(i=0;i<m;i++){
        cin>>c>>d;c--;d--;

            if(a[c].w == 1 && a[d].w == 1)
                if( get(c) != get(d) )
                    merge(c,d);
    }



    for(i=0;i<n;i++)
        a[i].id = get ( a[i].id );

    qsort(a,n,sizeof(a[0]),cmpfun);


    r=0;f=0;

    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++)
            if( a[i].id != a[j].id)
                break;
        j--;

        f +=  (j-i)*(j-i+1)/2;
        r += j-i+1>=2?j-i+1:0;
        i = j;
    }
cout<<f<<" "<<r<<endl;

return 0;
}
