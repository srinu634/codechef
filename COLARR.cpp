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
#define MAX 2000
#define NEGINF -10000000
typedef long long int ll;
#define scan(x) scanf("%lld",&x)
#define print(x) printF("%lld\n",x");
#define rep(i,n) for(i=0;i<n;i++)
#define rrep(i,n) for(i=n-1;i>=0;i--)
using namespace std;

ll n,m,k,b[MAX][MAX],c[MAX][MAX],res;

struct node {
ll curr;
ll final;
ll cost;
ll pos;
ll icost;
ll diff;
}a[MAX];


int cmpfun(const void *p, const void *q)
{
struct node * a = ((struct node *)p);
struct node * b = ((struct node *)q);
return (b->diff - a->diff);
}


int main() {

    ll t,i,j,index;

    scan(t);

    while(t--){
        scan(n);scan(m);scan(k); //cin>>n>>m>>k;

        rep(i,n){
            scan(a[i].curr);
            a[i].curr--;
            a[i].pos = i;
        }


        rep(i,n)
            rep(j,m)
                scan(b[i][j]);//cin>>b[i][j];



        rep(i,n)
            rep(j,m)
                scan(c[i][j]); //cin>>c[i][j];

	rep(i,n)
	a[i].icost = b[i][  a[i].curr ] ;

                rep(i,n){
                    res = NEGINF;
                    rep(j,m)
                        if( res  < b[i][j]-c[i][j]) {
                            index = j; //j-th colour
                            res = b[i][j] - c[i][j];
                        }

                    a[i].cost = res;
                    a[i].final = index;
                    a[i].diff = a[i].cost - a[i].icost;
                }

            qsort(a,n,sizeof(a[1]),cmpfun);

           // rep(i,n)
            //   cout<<a[i].curr+1<<" "<<a[i].final+1<<" "<<a[i].cost<<" "<<a[i].pos+1<<" "<<a[i].icost<<endl;

            res = 0;
            ll count = 0;

            rep(i,n){
                if(a[i].curr != a[i].final && count < k){
				//	cout<<"count is" <<count<<" "<<"postition is"<<a[i].pos<<endl;
                    count++;
                    res += a[i].cost;
                }
                else
                    res += a[i].icost ; // Initial pos + initial color
		//cout<<"result is "<<res<<endl;
            }


            cout<<res<<endl;
    }//t


return 0;
}//main
