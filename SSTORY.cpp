/*  Finding Longest Common Substring of two strings using Suffix Arrays
    O(n*logn*logn) for SA, O(nlogn) for LCP
    A#B , LCS is the nothing but the max LCP such that one index is < index(#) && another > index(#)
    http://discuss.codechef.com/questions/21385/a-tutorial-on-suffix-arrays -> Used this as code ref.
    http://p--np.blogspot.in/2011/12/suffix-array.html -> Theory ref.
*/

#include<iostream>
#include<algorithm>
using namespace std;
#define MAX 500005
typedef long  ll;
#define rep(i,n) for(i=0;i<n;i++)
#define rrep(i,n) for (i=n-1;i>=0;i--)
ll p[22][MAX]; //SA,LCP
ll stp,cnt,index;
ll res[MAX];

struct node{
    ll si[2]; //sort index
    ll pos; // position
}s[MAX];

int cmpfun(struct node a,struct node b){
    if(a.si[0] != b.si[0]){
      return  a.si[0] < b.si[0] ? 1 : 0; // If initial prefixes dont match
    }

    return a.si[1] < b.si[1] ? 1 : 0 ; // sort wrt to next 2^k segment
}

ll lcp(ll x,int y,ll n){
    ll i, res = 0;
    if (x == y) return n - x;  //Base Case, never true for this prob.
    for (i = stp - 1; i >= 0 && x < n && y < n; i --) //stp is already calculated in buildSA
        if (p[i][x] == p[i][y]) //As the prefixes match
            x += 1 << i, y += 1 << i, res += 1 << i;  //Start for prefix match from x+2^i,y+2^i
    return res;
}

void buildSA(string str,ll n){
    ll i,j,k;

    rep(i,n)
        p[0][i]  = str[i] - '#';//Sorted according to the 1st char

    for(stp=1, cnt = 1; cnt < n; stp++, cnt *= 2) {
        rep(i,n){
            s[i].si[0] = p[stp-1][i];
            s[i].si[1] = i + cnt < n? p[stp-1][i+cnt] : -1; //-100 is equivalent to $ append at the end.
            s[i].pos = i;
        }
        sort(s,s+n,cmpfun); //String compare in O(1) to reduce the running time

        for(i=0;i<n;i++)
            p[stp][s[i].pos] = i>0 && s[i].si[0]== s[i-1].si[0] && s[i].si[1]== s[i-1].si[1]? p[stp][s[i-1].pos] : i;
            // Both prefixes match till 2^stp-1 && also till 2^stp,give them the same index
            // Or else assign it an sort index = i
    }//for
    //NOTE: s[i].pos is our suffix array
}//SA

int main(){
    ll i,j,n,temp;
    string s1,s2,s3;

    cin>>s1>>s2;

    s3 = s1 + "#" + s2;
    index = s1.size();

    buildSA(s3,s3.size());
    n = s3.size();

    ll ans,ansindex;
    rep(i,n)
        res[i] = -1;
    ans = 0;
    ansindex = 1 << 30 ;

    for(i=1;i<n;i++)
            res[i] = s[i].pos<s[i-1].pos? lcp(s[i].pos,s[i-1].pos,n) : lcp(s[i-1].pos,s[i].pos,n) ; // O(nlogn)

    for(i=1;i<n;i++)  //LOOKS LIKE TLE FOR SURE
        if(  s[i].pos < index  ){
             int j1,j2; j1 = i;j2 = i;
             do{
                 j1--;
                 if(s[j1].pos<=index) break;
                 temp = lcp(s[i].pos,s[j1].pos,n);
                 if(ans<temp) {ans = temp; ansindex = s[j1].pos;} else if(ans==temp) ansindex = min(ansindex,s[j1].pos);
                 } while(j1>=0);

             do{
                j2++; if(j2==n)break;
                if(s[j2].pos<=index ) break;
                temp = lcp(s[i].pos,s[j2].pos,n);
                if(ans<temp) {ans = temp; ansindex = s[j2].pos;} else if(ans==temp) ansindex = min(ansindex,s[j2].pos);
                }while(j2<n);

        }

    if( ans == 0){
        cout<<"0"<<endl;
        return 0;
    }

    for(i=ansindex;i<ansindex+ans;i++)
        cout<<s3[i];
    cout<<endl;
    cout<<ans<<endl;
    return 0;
}
