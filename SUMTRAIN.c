#include<stdio.h>

int a[100][100];


int  pathFinder(int curr_row,int curr_col,int row);

int main( ) {
int t;
int i;
int row;
int j;
int k;

scanf("%d",&t);

for(i=0;i<t;i++) {
scanf("%d",&row);
for(j=0;j<row;j++) {
for(k=0;k<=j;k++)
scanf("%d",&a[j][k]);
}
printf("%d\n",pathFinder(0,0,row) );


}

return 0;
}

int pathFinder(int curr_row,int curr_col,int row) {
int sum1;
int sum2;
sum1=0;
sum2=0;

if( curr_row >=  row)
return 0; //base case

sum1=sum1+ a[curr_row][curr_col]+pathFinder(curr_row+1,curr_col,row );
sum2=sum2 + a[curr_row][curr_col]+pathFinder(curr_row+1,curr_col+1,row);

if(sum1>sum2)
return sum1;
else
return sum2;

}

