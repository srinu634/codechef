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
#define rep(i,n) for(i=0;i<n;i++)
typedef long long int ll;
using namespace std;

struct node {
	ll v;
	struct node *next;
}* vertex[MAX];

ll visited[MAX],n,m,r,f,open[MAX], R[MAX],F,a,b,newsum;


void add ( int i,int j) {
struct node * temp;
temp=vertex[i];

vertex[i] = (struct node *) malloc( sizeof(struct node) );
vertex[i]->v = j;
vertex[i]->next=temp;
}

ll dfs(ll v ) {
ll leaf_flag,flag;
struct node *trav;

trav = vertex[v];
flag = 0;
leaf_flag = true;


if( open[v] == 1 && visited[v] == false)
    F++;

visited[v] = true;
//cout<<"v "<<v<<" "<<"trav "<<" "<<trav<<" "<<"open[v] "<< open[v]<<endl;

	while ( trav!= NULL ) {
		if ( visited [ trav->v ] == 0 ) {
            leaf_flag = false;
			visited [ trav->v ] = 1;
			if( open[trav->v] == 1)
                F++;
			dfs( trav->v );
			}
			trav=trav->next;
		}

	//Done with all it's children
	trav = vertex[v];

	if(leaf_flag == true){
        R[v] = open[v];
        return open[v];
        }

		while(trav != NULL){
            R[ v ] += R [trav->v];
            if( R[trav->v] > 0)
                flag++;
            trav = trav->next;
		}

		if(flag > 0 || open[v] == 1)
            R[v]++;
        if(flag >= 2 || open[v] == true)
            newsum = max(newsum,R[v]);

return flag;
}//dfs

void dfs1(ll);
void scan();

int main( ) {
 ll i,j,flag;
struct node *trav;

rep(i,n){
    visited[i] = false;
    vertex[i] = NULL;
}

    scan();

 rep(i,n)
    R[i] = 0;

  r = 0;
  f = 0;

rep(i,n)
    if( visited[i] == 0){
        F = 0;
        newsum = 0;
        flag = dfs(i);
        if(F>1)
            f += F*(F-1)/2;
      //    rep(j,n)
   //        cout<<visited[j]<<" ";cout<<endl;
        if(flag == 1 && newsum>=2)
            r+=newsum ;
        if( flag >= 2 && R[i]>=2)
            r += R[i];
//cout<<f<<" "<<r<<endl;
}

cout<<f<<" "<<r<<endl;
return 0;
}//main

void scan(){
ll i,j;

 cin>>n>>m;

 rep(i,n)
    cin>>open[i];

rep(i,m)
	cin>>a>>b, add(a-1,b-1),add(b-1,a-1);
}
