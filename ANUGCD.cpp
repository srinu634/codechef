// Sieve for each  rootn segment.
#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
#define s(x) scanf("%d",&x);
#define p(x,y) printf("%d %d\n",x,y);
#define rep(i,n) for(i=0;i<n;i++)
#define MAX 100007
#define lim 100000
using namespace std;

int a[MAX];
int num[350][MAX]; // which stores the maximum number for that segment;
int fre[350][MAX]; // fre. of that num.
int n,rootn,g,x,y,m;

void preprocess(){
    int i,j,sc,b[MAX],count,k,i1,i2; //segmentcount

    rootn = floor(sqrt(n));
    i = 1;sc = 1;

    while(true){
        if(i+rootn>=n)
            break;
        j = i + rootn  ;
        for(k=1;k<=lim;k++)
            fre[sc][k] = 0,num[sc][k] = 0;

        for(k=i;k<=j;k++)
            b[k-i] = a[k];

        sort(b,b+j-i+1);

        for(i1=0;i1<j-i+1;i1++){
            for(i2=i1;i2<j-i+1;i2++)
                if(b[i2] != b[i1])
                    break;
                i2--;

            if(b[i1]==1){fre[sc][1] = i2-i1+1;continue;  }

            for(k = b[i1];k<=lim;k+=b[i1])  //sieve
                num[sc][k] = b[i1], fre[sc][k]=i2-i1+1 ;

            i1=i2;
        }

        sc++;
    i = j+1;
    }

    for(;i<=n;i++)
        for(k=a[i];k<=lim;k++)
            fre[sc][k]=0; //clear any prev. values

    for(;i<=n;i++)
        for(k=a[i];k<=lim;k++)
            num[sc][k] = k , fre[sc][k]++; // For the remaining part

}//preprocess

 int gcd( int a, int b) {
if(b==0)
return a;
return gcd(b,a%b);
}


int main(){
    int rn,i,j,ans,anscount,cx,cy;
    double r;//rootn

    s(n);s(m);
    rn = sqrt(n); rn = r;
    rep(i,n)
        s(a[i]);

    preprocess(); //O(sieve*rootn)

    while(m--){
            s(g);s(x);s(y);
            ans = -1; anscount = 0;

            if(y-x<=2*rootn){
                    for(i=x;i<=y;i++)
                        if(gcd(a[i],g) > 1)
                            if(a[i]>ans)
                                ans = a[i];
                    for(i=x;i<=y;i++)
                        if(a[i]==ans)
                            anscount++;
                    if(anscount==0){cout<<"-1 -1"<<endl;continue;}
                    cout<<ans<<" "<<anscount<<endl;
                    continue;
            }

            cx = ceil(x/rn);
            cy = floor(y/rn); // rootn segments
            for(i=cx;i<cy;i++)
                if( num [i][g] > ans )
                    ans = num[i][g] , anscount = fre[i][g];
                else if(ans == num[i][g])
                    anscount+= fre[i][g];
        for(i=x;i<cx*rn;i++)
            if(num[i/rn+1][a[i] ] > ans)
                ans = num[i/rn+1][a[i] ] , anscount = fre[i/rn+1][a[i] ];
            else if( num[i/rn+1][a[i] ] == ans )
                anscount += fre[i/rn+1][a[i] ];

        for(i=cy*rn+1;i<=y;i++)
            if(num[i/rn+1][a[i] ] > ans)
                ans = num[i/rn+1][a[i] ] , anscount = fre[i/rn+1][a[i] ];
            else if( num[i/rn+1][a[i] ] == ans )
                anscount += fre[i/rn+1][a[i] ];
        if(anscount==0){cout<<"-1 -1"<<endl;continue;}
                    cout<<ans<<" "<<anscount<<endl;


    }

    return 0;
}
