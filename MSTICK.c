#include<stdio.h>
#include<math.h>
#define MAX 100000
#define INFINITY 1000000100

int treemax[262145];
int treemin[262145];
int a[MAX+100];
int n_ceil,size;
int i,j,n,q,l,r;//iterators
long int max_left,max_right,max_lr,max1,min_lr;
double result1,result2;
	
	int searchmax(int qs,int qe,int left,int right,int index) {
	
	int mid,p1,p2;
		mid= (left+right)/2;
//		printf("(%d,%d,%d,%d,%d)\n",qs,qe,left,right,index);
	if ( qe<left || qs>right)
	return -1; //out of index
	if ( qs <=left && qe >=  right ) 
	return treemax[index];		 
	else if (qe<mid )
		return searchmax(qs,qe,left,mid,2*index+1);
	else if (qs>mid )
		return searchmax(qs,qe,mid+1,right,2*index+2);
	else return maxint ( searchmax(qs,mid,left,mid,2*index+1),searchmax(mid+1,qe,mid+1,right,2*index+2) ); 
	}//searchmax
	
		int searchmin(int qs,int qe,int left,int right,int index) {
	int mid,p1,p2;
		mid= (left+right)/2;
	if ( qe<left || qs>right)
	return INFINITY; //out of index
else	if ( qs <= left && qe >=  right ) 
	return treemin[index];
	else if (qe<mid )
		return searchmin(qs,qe,left,mid,2*index+1);
	else if (qs>mid )
		return searchmin(qs,qe,mid+1,right,2*index+2);		
else	return minint ( searchmin(qs,mid,left,mid,2*index+1),searchmin(mid+1,qe,mid+1,right,2*index+2) ); 
	}//searchmin
	
	int max(int x,int y) {
	return treemax[x]>treemax[y]?treemax[x]:treemax[y];
	}
		int min(int x,int y) {
	return treemin[x]<treemin[y]?treemin[x]:treemin[y];
	}
	int maxint(int x,int y) {
	return x>y?x:y;
	}
	int minint(int x,int y){
	return x<y?x:y;
	}
	
		void addmax(int left,int right,int index) {
		int mid;
		mid = (left+right)/2;	
	if ( left==right) {
		treemax[index] =a[left];
			return;
	}//encountered a leaf
	addmax(left,mid,2*index+1);
	addmax(mid+1,right,2*index+2);
	treemax[index] = max( index*2+1,index*2+2);	
	}//add
		
		void addmin(int left,int right,int index) {
		int mid;
		mid = (left+right)/2;		
	if ( left==right ) {
		treemin[index] =a[left];
			return;
	}//encountered a leaf
	addmin(left,mid,2*index+1);
	addmin(mid+1,right,2*index+2);
	treemin[index] = min( index*2+1,index*2+2);	
	}//add	
	
		
	int main( ) {
	scanf("%d",&n);			
	
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	

	addmax(0,n-1,0);
	addmin(0,n-1,0);

	scanf("%d",&q);	
	for(i=0;i<q;i++) {
	scanf("%ld %ld",&l,&r);
		if(l!=0)
			max_left=searchmax(0,l-1,0,n-1,0);
		else
			max_left=0;
//	printf("maxleft = %d\n",max_left);
	
		if(r!=n-1)
			max_right=searchmax(r+1,n-1,0,n-1,0);
		else
		max_right=0;
//	printf("maxright = %d\n",max_right);

	if ( max_right > max_left)
		max_left = max_right;      //O(logn)     //maxleft will have the greatest value from o to l-1,r+1,n-1
	
		min_lr =searchmin(l,r,0,n-1,0);
		max_lr = searchmax(l,r,0,n-1,0);

		//printf("min_lr = %d max_lr=%d\n",min_lr,max_lr);
		
		
		result1=min_lr+max_left;
		result2=  (min_lr+max_lr);
		result2=(double)result2/2;
		if( result1>=result2)
		printf("%.1lf\n",result1);
		else
		printf("%.1lf\n",result2);

	}//query loop
	
	
return 0;	
}//main
