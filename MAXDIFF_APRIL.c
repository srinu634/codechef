#include<stdio.h>
#include<stdlib.h>



int a[100];

void merge(int low,int mid,int high) {
int *temp;
int left,right;
int i;
int k;
k=0;
left=low;
right=mid+1;
temp = (int *)malloc( sizeof(int) *(high-low+1) );
while( left<=mid && right<=high) {
if( a[left]<a[right]) {
temp[k]=a[left];
k++;
left++;
}
else
{
	temp[k]=a[right];
	k++;
	right++;
}
}
while( left<=mid){ 
temp[k]=a[left];
k++;
left++;
}
while(right<=high) {
temp[k]=a[right];
k++;
right++;
}
for(i=low;i<=high;i++)
a[i]=temp[i-low];
free(temp);
}//merge
	

void mergesort(int low,int high) {
if(low!=high) {
int mid = (low+high)/2;
mergesort(low,mid);
mergesort(mid+1,high);
merge(low,mid,high);
}
}


		int main( ) {

int t,n,k;
int i,j;
long int sum1;
long int sum2;

scanf("%d",&t);

for(i=0;i<t;i++) {

sum1=0;
sum2=0;
scanf("%d %d",&n,&k);

if(k>(n/2))
k=n-k;

for(j=0;j<n;j++) 
scanf("%d",a+j);


mergesort(0,n-1);

for(j=0;j<k;j++)
sum1+=a[j];

for(;j<n;j++)
sum2+=a[j];

printf("%ld\n",sum2-sum1);

}

return 0;
}//main
