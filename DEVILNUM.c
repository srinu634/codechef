#include<stdio.h>
#define MAX 1000001
int temp[MAX];

int main( ){

int n,t;
int i,j,k;
int count;
int current;
count=0;
current=1;

for(i=1;i<MAX;i++) {
j=i;
while(j>0){ 
if(j%10 !=3)
if(j%10!=1  ) {
temp[i]=current;
break;
}//if
j=j/10;
}//while
if(j==0) {
current=i;
temp[i]=current;
}
}

scanf("%d",&t);

for(i=0;i<t;i++) {
scanf("%d",&n);
printf("%d\n",temp[n]);
}

return 0;
}//main
