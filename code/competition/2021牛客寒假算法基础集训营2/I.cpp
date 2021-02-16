#include <bits/stdc++.h>
using namespace std;
#pragma optimize(2)
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
const int inf = 0x7FFFFFFF;
typedef long long ll;
typedef double db;
typedef long double ld;
template<class T>inline void MAX(T &x,T y){if(y>x)x=y;}
template<class T>inline void MIN(T &x,T y){if(y<x)x=y;}
template<class T>inline void rd(T &x){
   x=0;char o,f=1;
   while(o=getchar(),o<48)if(o==45)f=-f;
   do x=(x<<3)+(x<<1)+(o^48);
   while(o=getchar(),o>47);
   x*=f;
}
template<class T>
void wt(T x){
   if(x < 0) putchar('-'), x = -x;
   if(x >= 10) wt(x / 10);
   putchar('0' + x % 10);
}
#define MP make_pair
#define pb push_back
#define pt putchar
#define yx_queue priority_queue
#define lson(pos) (pos<<1)
#define rson(pos) (pos<<1|1)
#define y1 code_by_Rand0w
#define yn A_muban_for_ACM
#define j1 it_is just_an_eastegg
#define lr hope_you_will_be_happy_to_see_this
#define int long long
#define rep(i, a, n) for (register int i = a; i <= n; ++i)
#define per(i, a, n) for (register int i = n; i >= a; --i)
const ll llinf = 4223372036854775807;
const ll mod = (1 ? 1000000007 : 998244353);
const ll mod2 = 999998639;
const int m1 = 998244353;
const int m2 = 1000001011;
const int pr=233;
const double eps = 1e-7;
const int maxm= 1;
const int maxn = 4000100;
int n;
int ans=0;
bool is_prime[maxn];
vector<int> primes,weis;
void euler(){
    is_prime[1] = 1;
    for(int i=2;i<maxn;i++){
        if(!is_prime[i])
            primes.push_back(i);
        for(int j=0;j<primes.size()&&primes[j]*i<maxn;j++){
            is_prime[primes[j]*i]=1;
            if(i%primes[j]==0)
                break;
        }
    }
}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
inline int weishu(int a){
    int ans=0;
    while(a){
        ans++;
        a/=10;
    }
    return ans;
}
void dfs(int now,int ed,int tt){
    ans+=tt;
    ans%=mod;
    for(int i=ed;i<primes.size()&&primes[i]*now<=n;i++)
        dfs(now*primes[i],i,(tt*weis[i]%mod+primes[i])%mod);
}
void work()
{
    rd(n);
    euler();
    for(int i=0;i<primes.size();i++)
        weis.push_back(powmod(10,weishu(primes[i])));
    dfs(1,0,0);
    wt(ans),pt('\n');
}
signed main()
{
   #ifndef ONLINE_JUDGE
   freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
#endif
//std::ios::sync_with_stdio(false);
//cin.tie(NULL);
int t = 1;
//cin>>t;
while (t--)
    work();
return 0;
}