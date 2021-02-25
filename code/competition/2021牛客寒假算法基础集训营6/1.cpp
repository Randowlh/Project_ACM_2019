#include<bits/stdc++.h>
using namespace std;
const int mod= 1000;
#define ll long long
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
int main(){
    ll n;
    while(cin>>n){
        int ans=powmod(5,n);
        if(ans<100)
            cout<<0;
        if(ans<10)
            cout<<0;
        if(ans==0){
            cout<<0<<endl;
            continue;
        }
        cout<<ans<<endl;
    }
}