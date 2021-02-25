#include<bits/stdc++.h>
using namespace std;
const int mod= 998244353;
#define int long long
#define ll long long
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
signed main(){
    int n;
    cin>>n;
    int xiangshu=(n-2)/2;
    int fst=n-3;
    int ed=n-3-xiangshu;
    int ans=0;
    ans+=(powmod(2,fst+1)-powmod(2,ed+1))%mod+mod;
    ans%=mod;
    int tt=n-xiangshu;
    tt%=4;
    if(tt==3)
        cout<<ans<<endl;
    else if(tt==1){
        cout<<(ans+powmod(2,xiangshu+1))%mod<<endl;
    }else {
        cout<<(ans+powmod(2,xiangshu))%mod<<endl;
    }
}