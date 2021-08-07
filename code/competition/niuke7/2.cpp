// #pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define mst(a,x) memset(a,x,sizeof(a))
#define endl "\n"
#define fr first
#define sc second
#define debug cout<<"DEBUG\n";
#define OMG(a,n) rep(i,1,n) cout<<a[i]<<" "; cout<<endl;
#define OMG2(a,n,m) rep(i,1,n) {rep(j,1,m) cout<<a[i][j]<<" "; cout<<endl;}
template <typename Type> void RIP(Type x) {cout<<x<<endl;}template <typename Type, typename... Targs>void RIP(Type x, Targs... args) {cout<<x<<" ";RIP(args...);}
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
typedef long long ll; typedef unsigned long long ull; typedef pair<int,ll>pil; typedef pair<int,int>pii; typedef pair<ll,ll>pll;
const int N=1e6+10; const double eps=1e-9;
const int inf=0x3f3f3f3f; const ll INF=0x3f3f3f3f3f3f3f3f;
const int mo=(1?998244353:1000000007); ll mul(ll a,ll b,ll m=mo){return a*b%m;} ll fpow(ll a,ll b,ll m=mo){ll ans=1; for(;b;a=mul(a,a,m),b>>=1)if(b&1)ans=mul(ans,a,m); return ans;}
inline ll read(){ll x=0,tag=1; char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')tag=-1;for(; isdigit(c);c=getchar())x=x*10+c-48;return x*tag;}
typedef double lf; const lf pi=acos(-1.0); lf readf(){lf x; if(scanf("%lf",&x)!=1)exit(0); return x;} template<typename T> T sqr(T x){return x*x;}

int B(int x,int i){
    return (x>>i)&1;
}
void Solve(){
    ll x=read(),s=read();
    ll ans=1;
    rep(i,0,30){
        int bx=B(x,i),bs=B(s,i);
        if(!bs&&bx) {
            ans=0;
        }
        if(bs&&bx){
            ans*=2;
        } 
    }    
    cout<<ans<<endl;
}
int main(){
    // #ifndef ONLINE_JUDGE
        // freopen("in.txt","r",stdin);
        // freopen("out.txt","w",stdout);
    // #endif
    //ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T=1; //T=read();
    rep(kase,1,T){
        Solve();
    }
    return 0;
}