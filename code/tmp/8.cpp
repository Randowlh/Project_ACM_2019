#include<bits/stdc++.h>
using namespace std;
#define int long long
int dp[50010];
int mod=998244353;
void work(){
    int n,k,m;
    scanf("%lld%lld%lld",&n,&k,&m);
    for(int i=0;i<=n;i++)
        dp[i]=0;
    dp[n]=1;
    for(int i=n;i>=0;i--){
        for(int j=1;j<=m;j++){
            if(i-10*j>=0)
                dp[i-10*j]=(dp[i-10*j]+dp[i])%mod;
            else break;
        }
        for(int j=1;j<=k;j++){
            if(i-j>=0)
                dp[i-j]=(dp[i-j]+dp[i])%mod;
            else break;
        }
    }
    printf("%lld\n",dp[0]);
}
signed main(){
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
        work();
}