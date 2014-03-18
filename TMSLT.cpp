#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
#define MAX 3000005
#define g getchar_unlocked()
#define mod 1000000

int csort[1000005];

ll s[MAX];

void scanint(ll *z){
int x, neg = 0;
register int c = getchar_unlocked();
x=*z;
x = 0;
for(;((c<48 || c>57) && c != '-');
c = getchar_unlocked());
if(c=='-')
{
neg=1;
c=getchar_unlocked();
}
for(;c>47 && c<58;c = getchar_unlocked())
x = (x<<1) + (x<<3) + c - 48;
if(neg)
x=-x;
*z=x;
}

int main(){
    ll a,b,c,d,t,i,n,flag;

    cin>>t;//scanint(&t);

    while(t--){

        cin>>n>>a>>b>>c>>d; //scanint(&n); scanint(&a); scanint(&b); scanint(&c); scanint(&d);

       s[0] = d;

       for(i=1;i<n;i++)
        s[i] =   ( b*s[i-1] + c + a*s[i-1]*s[i-1] + mod) %mod;

       for(i=0;i<=1000000;i++)
        csort[i] = 0;
        flag = 0;

    for(i=0;i<n;i++)
        csort[ s[i] ]++;

        ll s1,s2;
       s1=0;s2=0;

    for(i=1000000;i>=0;i--){
        while( csort[i] > 0){
            if(flag == 1){
                flag = flag^1;
                s1 += i;
            }
            else{
                flag = flag^1;
                s2 += i;
            }
        csort[i]--;
        }
    }





        printf("%lld\n", s1-s2>=0?s1-s2:s2-s1  );

    }

    return 0;
}
