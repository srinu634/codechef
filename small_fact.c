#include<stdio.h>

int a[200]; //array to store digits


void fact (int n) {

int index=0;
int temp;
int store;
int i,j;//used as iterators.
int m;
m=n;

while(m>0){ 
a[index++]=m%10;
m=m/10;
}  //index will keep track of number of digits.


for(i=n-1;i>=1;i--)  {

temp=0; //initialised to zero everytime.
j=0;

while(j<index) {
store=a[j]*i +temp;
a[j]=store%10;
temp=store/10;
j++;
}//multiplication.

while(temp>0) {
a[j]=temp%10;
temp=temp/10;
j++;
} //will copy leftover digits from temp to array.

index=j; //since j will contain the number of digits.
}

for(i=index-1;i>=0;i--)
printf("%d",a[i]);
printf("\n");

}//end of fact

int main( )
{
int t; //test cases
int n; //number
scanf("%d",&t);

int i; //to iterate

for(i=1;i<=t;i++) {
scanf("%d",&n);
fact(n);
}
return 0;
}
