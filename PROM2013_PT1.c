#include<stdio.h>

int main( ) {
int t,a;
int i;

scanf("%d",&t);


for(i=0;i<t;i++) {
scanf("%d",&a);

if( a==0) {  
printf("NO\n");
continue;
}

if(a==180) {
printf("NO\n");
continue;

}

if( (360%(180-a))  == 0 )
 printf("YES\n");
 else
 printf("NO\n");

}
return 0;
}//main
