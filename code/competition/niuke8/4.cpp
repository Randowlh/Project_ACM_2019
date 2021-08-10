#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
template<class T>inline void read(T &x){x=0;char o,f=1;while(o=getchar(),o<48)if(o==45)f=-f;do x=(x<<3)+(x<<1)+(o^48);while(o=getchar(),o>47);x*=f;}
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=(b);i--)
#define INF 0x3f3f3f3f
ll gcd(ll a,ll b){ while(b^=a^=b^=a%=b); return a; }
#define int ll
const int med = 4933;
ll qpow(ll d,ll c){//快速幂
    ll res = 1;
    while(c){
        if(c&1) res=res*d%med;
        d=d*d%med;c>>=1;
    }return res;
}
inline ll niyuan(ll x){return qpow(x,med-2);}

int n,m,k,a,l;
int res,xi,yi,zi;
void solve(){
    cin>>n>>m>>k>>a>>l;
    if(n==m){
        cout<<a<<endl;
        return;
    }
    res = 1;
    rep(i,1,k){
        cin>>xi>>yi>>zi;
        if(xi==0)
            continue;
        res = res*(zi-yi)%med;
        res = res*niyuan(zi)%med;
    }
    res = (res+a)%med;
    cout<<res<<endl;
}

signed main(){
    solve();
}