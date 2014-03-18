#include<stdio.h>
#include<algorithm>
using namespace std;

struct node{
    int l;
    int r;
}ans[20000];

int main(){

    int n,a[20000],i,j,index,b[20000],q;

    scanf("%d",&n);

    for(i=0;i<n;i++)
        scanf("%d",a+i);

    q = 0;

    for(i=0;i<n;i++){
        index = i;
        for(j=i;j<n;j++)
            if( a[index] > a[j])
                index = j;
        if(i+1==index+1)
            continue;
        //printf("%d %d\n",i+1,index+1);
        ans[q].l = i+1;
        ans[q].r = index+1;
        q++;

        for(j=0;j <= (index-i)/2;j++)
            swap(a[i+j],a[index-j]);

    }

    printf("%d\n",q);

    for(i=0;i<q;i++)
        printf("%d %d\n",ans[i].l,ans[i].r);

    return 0;
}
