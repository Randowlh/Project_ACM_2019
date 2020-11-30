#include<bits/stdc++.h>
#define int long long
int feb[200010];
int mod=998244353;
signed main(){
    feb[1]=1;
    feb[2]=2;
    for(int i=3;i<200004;i++){
        feb[i]=(feb[i-1]+feb[i-2])%mod;
    }
    int t;
    scanf("%lld",&t);
    for(int i=1;i<=t;i++){
        int n;
        scanf("%lld",&n);
        int ans=1;
        for(int i=1;i<=n;i++)
            ans=(ans*feb[i])%mod;
        printf("%lld\n",ans);
    }
}