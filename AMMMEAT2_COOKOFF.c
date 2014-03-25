#include<stdio.h>

int main( ) {
int t,n,k;
int i,j,l;
scanf("%d",&t);
for( i =0;i<t;i++) {
scanf("%d %d",&n,&k);

if(n==1) {
printf("1\n");
continue;
}
if ( k> ( n-2)/2+1  )
{
	printf("-1\n");
	continue;
}
for(j=0;j< k;j++) 
printf("%d ",2*(j+1 ) );
printf("\n");
}
return 0;
}//main



