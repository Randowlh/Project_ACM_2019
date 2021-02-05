#include<bits/stdc++.h>
#define ll long long
ll mod=1e9+7;
using namespace std;
ll pre[1100000];
ll hvu[1100000];
ll nos[1100000];
ll nosu[1100000];
ll dp[1100000];
int main(){
    ll n;
    cin>>n;
    pre[0]=1;
    for(int i=1;i<=n+100;i++)
        pre[i]=(pre[i-1]*24)%mod;
    hvu[1]=1;
    for(int i=2;i<=n+100;i++)
        hvu[i]=(hvu[i-1]*25%mod+pre[i-1])%mod;
    nos[1]=1;
    nosu[1]=0;
    for(int i=2;i<=n+100;i++){
        nos[i]=(nos[i-1]*25+pre[i-1])%mod;
        nosu[i]=(nosu[i-1]*25+nos[i-1])%mod;
    }
    dp[2]=1;
    for(int i=3;i<=n;i++)
        dp[i]=(dp[i-1]*26%mod+hvu[i-1]+nosu[i-1])%mod;
    int ans=0;
    for(int i=1;i<=n;i++)
        ans=(ans+dp[i])%mod;
    cout<<ans<<endl;
}