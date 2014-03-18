#include<iostream>
using namespace std;

int a[30][20000];
int k[30];
int b[30][30]; //compatibility
int ans1,n,m;


void count(int index,int * arr   ,int ans){

    int i;
    int temp[20];

    for(i=0;i<20;i++)
        temp[i] = arr[i];

    if(index == m ){
        if( ans1 < ans)
            ans1 = ans;

        return ;
        }
    //If incopatible return -1;

      count(index + 1,temp,ans); //exculding

    if( arr[index] == 0)
        return; // As it is incompatible

    for(i=0;i<m;i++)
        temp[i] = ( arr[i]  &  b[index][i] );

   // cout<<"Including "<<index<<endl;
     count(index + 1, temp,ans+1);  //including

     if( ans1 < ans+ 1)
        ans1 = ans+ 1;   //two levels of updation : superstitious me. :D

}

int main(){
    int i,j,temp,j1;
    int arr[30];
    int *p;
    p = arr;

    cin>>n>>m;

    for(i=0;i<30;i++)
        for(j=0;j<20000;j++)
            a[i][j] = 0;

    for(i=0;i<m;i++){
        cin>>k[i];
        for(j=0;j<k[i];j++)
            cin>>temp,a[i][temp-1] = 1;
    }

    for(i=0;i<m;i++)
        for(j=0;j<m;j++)
            b[i][j] = 1;

    for(i=0;i<m;i++)
        for(j=0;j<m;j++)
            for(j1=0;j1<n;j1++)
                if( a[i][j1] == 1 && a[j][j1] == 1 && i!=j )
                    b[i][j] = 0;


    ans1 = -1;
    for(i=0;i<m;i++)
        arr[i] = 1;   // Initially Let's assume all customers satisfy our criteria


    count(0,arr,0);

    cout<<ans1<<endl;

    return 0;
