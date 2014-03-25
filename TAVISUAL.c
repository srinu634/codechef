#include<stdio.h>

	
		int main( ) {
 int N,L,R,C,T,Q;
 int i,j;//iterators.
 
 scanf("%d",&T);
 
 for( i=0;i<T;i++)  {
 	
 	scanf("%d %d %d",&N,&C,&Q);
 	
 	for( j=0;j<Q;j++) { 
 	scanf("%d %d",&L,&R);
 	if( L<=C && R>=C) 
 	C= R-C+L;
 
	 }//inner for loop
 	printf("%d\n",C);
 }//end of for
 
 return 0;
}//main
