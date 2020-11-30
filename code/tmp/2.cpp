#include<stdio.h>
int main(){
    int t;
    scanf("%d",&t);
    for(int q=0;q<t;q++){
        int n,k;
        scanf("%d%d",&n,&k);
        int cnt=0;
        for(int i=1;i<=n;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            if(b<k)
                continue;
            if((double)a/(double)b<0.5)
                continue;
            cnt++;
        }
        printf("%d\n",cnt);
    }
}