#include<stdio.h>


int main( ) {
int t=0;
int i=0;
int n=0;
int sum=0;

scanf("%d",&t);

for(i=0;i<t;i++) {
sum=0;

scanf("%d",&n);

while(n>0) {
sum = sum + n/5;
n=n/5;
}
printf("%d\n",sum);
}
return 0;
}//end of main
