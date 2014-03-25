#include<stdio.h>

int a[1000][1000];

int main( ) {

int m,t;
int i,j,k,l;
int min;

scanf("%d %d",&m,&t);

for( i = 0 ;i< m ;i++) 
for(j=0;j<m;j++) 
scanf("%d",&a[i][j]);


for(i=0;i<m-t+1;i++) {
for(j=0;j<m-t+1;j++) {

min = a[i][j];
for(k=0;k<t;k++) { 
for(l=0;l<t;l++) {
if(  a[k+i][j+l] < min) 
min =  a[k+i][j+l];
}//l loop
} // k loop
printf("%d ",min );
}//j
printf("\n");
}//for


return 0;
}//main
