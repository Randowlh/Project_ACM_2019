#include <bits/stdc++.h>
//#include <bits/extc++.h>
//using namespace __gnu_pbds;
//using namespace __gnu_cxx;
using namespace std;
#pragma optimize(2)
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#define rbset(T) tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>
const int inf = 0x7FFFFFFF;
typedef long long ll;
typedef double db;
typedef long double ld;
template<class T>inline void MAX(T &x,T y){if(y>x)x=y;}
template<class T>inline void MIN(T &x,T y){if(y<x)x=y;}
namespace FastIO
{
char buf[1 << 21], buf2[1 << 21], a[20], *p1 = buf, *p2 = buf, hh = '\n';
int p, p3 = -1;
void read() {}
void print() {}
inline int getc()
{
return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1++;
}
inline void flush()
{
fwrite(buf2, 1, p3 + 1, stdout), p3 = -1;
}
template <typename T, typename... T2>
inline void read(T &x, T2 &... oth)
{
int f = 0;x = 0;char ch = getc();
while (!isdigit(ch)){if (ch == '-')f = 1;ch = getc();}
while (isdigit(ch)){x = x * 10 + ch - 48;ch = getc();}
x = f ? -x : x;read(oth...);
}
template <typename T, typename... T2>
inline void print(T x, T2... oth)
{
if (p3 > 1 << 20)flush();
if (x < 0)buf2[++p3] = 45, x = -x;
do{a[++p] = x % 10 + 48;}while (x /= 10);
do{buf2[++p3] = a[p];}while (--p);
buf2[++p3] = hh;
print(oth...);
}
} // namespace FastIO
// #define read FastIO::read
// #define print FastIO::print
// #define flush FastIO::flush
#define spt fixed<<setprecision
#define endll '\n'
#define mul(a,b,mod) (__int128)(a)*(b)%(mod) 
#define pii(a,b) pair<a,b>
#define pow powmod
#define X first
#define Y second
#define lowbit(x) (x&-x)
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
const ll llinf = 4223372036854775851;
const ll mod = (0 ? 1000000007 : 998244353);
ll pow(ll a,ll b,ll md=mod) {ll res=1;a%=md; assert(b>=0); for(;b;b>>=1){if(b&1)res=mul(res,a,md);a=mul(a,a,md);}return res;}
const ll mod2 = 999998639;
const int m1 = 998244353;
const int m2 = 1000001011;
const int pr=233;
const double eps = 1e-7;
const int maxm= 1;
const int maxn = 510000;
class ffj{
    public:
    ll tail;
    ll pp[1000];
    bool miller_rabin(ll a,ll n){
        ll d=n-1,r=0;
        while(!(d&1))d>>=1,r++;
        ll x=pow(a,d,n);
        if(x==1)return 1;
        for(int i=0;i<r;i++){
            if(x==n-1)return 1;
            x=mul(x,x,n);
        }
        return 0;
    }
    bool ttprime(ll x){
        if(x<=1)return 0;
        static int num[]={2,3,5,7,13,29,37,89};
        for(int i=0;i<8;i++)if(x==num[i])return 1;
        for(int i=0;i<8;i++)if(!miller_rabin(num[i],x))return 0;
        return 1;
    }
    ll fun(ll x,ll c,ll mod){
        return (mul(x,x,mod)+c)%mod;
    }
    ll gcd(ll n,ll m){
        if(m==0)return n;
        return gcd(m,n%m);
    }
    ll pollard_rho(ll x){
        ll c=rand()%(x-1)+1;
        ll s=0,t=0;
        for(int goal=1;;goal<<=1,s=t){
            ll val=1;
            for(int step=1;step<=goal;step++){
                t=fun(t,c,x);
                val=mul(val,abs(s-t),x);
                if(step%127==0){
                    ll d=gcd(val,x);
                    if(d>1)return d;
                }
            }
            ll d=gcd(val,x);
            if(d>1)return d;
        }
    }
    void find_fac(ll x){
        if(x==1)return;
        if(ttprime(x)){
            pp[++tail]=x;
            return;
        }
        ll y=x;
        while(y==x)y=pollard_rho(x);
        find_fac(y),find_fac(x/y);
    }
    void fj(ll x){
        tail=0;
        find_fac(x);
    }
}test;
void work()
{
    int a;
    cin>>a;
    if(test.ttprime(a)){
        cout<<"T"<<endl;
    }else cout<<"F"<<endl;
}
signed main()
{
   #ifndef ONLINE_JUDGE
   //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif
    //std::ios::sync_with_stdio(false);
    //cin.tie(NULL);
    int t = 1;
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}