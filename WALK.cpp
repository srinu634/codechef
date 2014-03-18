#include<stdio.h>
#include<stdlib.h>

int max(int a,int b){
    return a>b?a:b;
}

int main(){

    int n,t,w,res,i;

    scanf("%d",&t);

    while(t--){

        scanf("%d",&n);
        res = -1;

        for(i=0;i<n;i++){
            scanf("%d",&w);
            res = max(res,w+i);
        }

    printf("%d\n",res);
    }

return 0;
}
