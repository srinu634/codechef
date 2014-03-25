#include<stdio.h>
#include<stdlib.h>

void merge(int *a,int low,int high) {

int *temp;
int k=0;
int left=low;
int mid=(low+high)/2;
int right=mid+1;
int i;

temp=(int *) malloc(sizeof(int) *(high-low+1) );

while(left<=mid && right <=high) {
if( a[left] <a[right]){  
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

void mergesort(int *a,int low,int high) {
if(low!=high) {
int mid = (low+high)/2;
mergesort(a,low,mid);
mergesort(a,mid+1,high);
merge(a,low,high);
}
}



int main( ) {
int t;
int *a;
int i;
scanf("%d",&t);

a=(int* )malloc( sizeof(int)*t);
for(i=0;i<t;i++)
scanf("%d",a+i);
mergesort(a,0,t-1);

for(i=0;i<t;i++)
printf("%d\n",a[i]);
free(a);
return 0;
}
