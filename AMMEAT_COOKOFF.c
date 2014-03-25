#include<stdio.h>

void merge(int ,int);
void mergesort(int,int);

	unsigned long long int a[7];
		
			int main( ) {
int i,j; //iterators
int t;
int n;
unsigned long long int sum,m;
scanf("%d",&t);

for(i=0;i<t;i++) {
scanf("%d %llu",&n,&m);
sum=0;
for(j=0;j<n;j++)
scanf("%llu",&a[j]);

mergesort(0,n-1);

	for(j=0;j<n;j++) 
sum+=a[j];

if( sum < m ) {
printf("-1\n");
continue;
} sum=0; 

for( j=0;j<n;j++) {
sum+=a[j];
//	printf("%d %d\n",sum,m);
if( sum>=m )
	break;

}//for

printf("%d\n",j+1);
}


return 0;
}//main


void merge(int low,int high) {

unsigned long long int *temp;
int k=0;
int left=low;
int mid=(low+high)/2;
int right=mid+1;
int i;

temp=(unsigned long long int *) malloc(sizeof(unsigned long long int) *(high-low+1) );

while(left<=mid && right <=high) {
if( a[left] >=a[right]){  
temp[k]=a[left];
k++;
left++;
}
else{ 
temp[k]=a[right];
k++;right++;
}

}

while(left<=mid) {
temp[k]=a[left];
left++;
k++;
}
while(right<=high) {
temp[k]=a[right];
k++;
right++;
}
for(i=low;i<=high;i++)
a[i]=temp[i-low];
free(temp);

}

void mergesort(int low,int high) {
if(low!=high) {
int mid = (low+high)/2;
mergesort(low,mid);
mergesort(mid+1,high);
merge(low,high);
}
}
