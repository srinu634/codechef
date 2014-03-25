#include<stdio.h>
#define MAX 10000

struct m { 
int value;
int index;
}min;

int server[MAX][200]; //each server can have 200 chunks
int chunk[200][MAX];	//each chunk can belong to 1000 servers
 int chunk_index[200];

		int main( ) {

int i,j,k; //iterators
int n,s; //chunks, servers
int c;

scanf("%d %d",&n,&s);


for(i=0;i<n;i++)
chunk_index[i]=0;

for(i=0;i<s;i++) {
scanf("%d",&c);
for(j=0;j<c;j++){ 
scanf("%d",&server[i][j] );
chunk [ server[i][j]  ][ chunk_index[server[i][j] ]  ] = i;  // [chunk_nmbr][index] = server ;
chunk_index[ server[i][j] ]++;
}
}//for

min.value=chunk_index[0];
min.index=0;

for(i=0;i<n;i++)
if ( min.value > chunk_index[i] ){ 
min.value=chunk_index[i];
min.index=i;    //this is nothing but the chunk number.
}  //i will have the index of the minimum value and its frequency.


/*for(i=0;i<s;i++) {  
	for(j=0;j<s;j++)
if( server[i][j]== -1)
break;
else
printf("%d ",server[i][j]);
printf("\n");
}*/

j=  min.value;

printf("%d\n",min.value);
for(i=0 ; i<j;i++)
printf("%d\n", chunk[min.index][i]) ; 

return 0;
}
