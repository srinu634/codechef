#include<stdio.h>

int a[100][100];




int main( ) {
int t;
int i;
int row;
int j;
int k;
int sum;

scanf("%d",&t);




for(i=0;i<t;i++) {

scanf("%d",&row);

for(j=0;j<row;j++) 
for(k=0;k<=j;k++)
scanf("%d",&a[j][k]);

for(j=row-1;j>0;j--)
for(k=0;k<j;k++)
{
if( a[j][k] >a[j][k+1])
sum=a[j][k];
else
sum=a[j][k+1]; 
a[j-1][k]+=sum;
}

printf("%d\n",a[0][0]);
}//for loop in i.

return 0;
}



