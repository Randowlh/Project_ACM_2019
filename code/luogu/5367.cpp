#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod= (0 ? 1000000007 : 998244353);
int n;
int t[1000100],date[1000100];
void add(int x){
    while(x<=n){
        t[x]++;
        x+=(x&-x);
    }
}
int sum(int x){
    int ans=0;
    while(x){
        ans+=t[x];
        x-=(x&-x);
    }
    return ans;
}
signed main(){
    scanf("%lld", &n);
    for(int i=1;i<=n;i++)
        scanf("%lld",&date[i]);
    add(date[n]);
    int now=1;
    int ans=0;
    for(int i=n-1;i>=1;i--){
        now=now*(n-i)%mod;
        ans+=now*sum(date[i])%mod;
        ans%=mod;
        add(date[i]);
    }
    cout<<ans+1<<endl;
}
