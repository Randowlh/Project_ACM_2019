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
#define read FastIO::read
#define print FastIO::print
#define flush FastIO::flush
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
#define il inline
#define rep(i, a, n) for (register int i = a; i <= n; ++i)
#define per(i, a, n) for (register int i = n; i >= a; --i)
const ll llinf = 4223372036854775807;
const ll mod = (0 ? 1000000007 : 998244353);
ll pow(ll a,ll b,ll md=mod) {ll res=1;a%=md; assert(b>=0); for(;b;b>>=1){if(b&1)res=mul(res,a,md);a=mul(a,a,md);}return res;}
const ll mod2 = 999998639;
const int m1 = 998244353;
const int m2 = 1000001011;
const int pr=233;
const double eps = 1e-7;
const int maxm= 1;
const int maxn = 5100000;
int premu[maxn+5];
int prephi[maxn+5];
int primes[maxn+5];
int tail=0;
bool is_prime[maxn+5];
unordered_map<int,int> memmu,memphi;
void euler()
{
    premu[1]=prephi[1]=1;
    is_prime[1] = 1;
    for (int i = 2; i <= maxn; i++)
    {
        if (!is_prime[i]){
            primes[++tail]=i;
            premu[i]=-1;
            prephi[i]=i-1;
        }
        for (int j = 1; j <=tail && i * primes[j] <= maxn; j++)
        {
            is_prime[i * primes[j]] = 1;
            if ((i % primes[j]) == 0){
                prephi[i*primes[j]]=prephi[i]*primes[j];
                break;
            }
            prephi[i*primes[j]]=prephi[primes[j]]*prephi[i];
            premu[i*primes[j]]=-premu[i];
        }
    }
    for(int i=1;i<=maxn;i++)
        premu[i]+=premu[i-1],prephi[i]+=prephi[i-1];
}
il int getmu(int n){
    if(n<=maxn) return premu[n];
    if(memmu.count(n))  return memmu[n];
    int ans=1;
    for(int l=2,r;l<=n;l=r+1){
        r=n/(n/l);
        ans-=(r-l+1)*getmu(n/l);
    }
    return memmu[n]=ans;
}
il int getphi(int n){
    if(n<=maxn) return prephi[n];
    if(memphi.count(n))return memphi[n];
    int ans=(n+1)*n/2;
    for(int l=2,r;l<=n;l=r+1){
        r=n/(n/l);
        ans-=(r-l+1)*getphi(n/l);
    }
    return memphi[n]=ans;
}
void work()
{
    int n;
    cin>>n;
    cout<<getphi(n)<<' '<<getmu(n)<<endll;
    // for(int i=1;i<=10;i++)
    //     cout<<prephi[i]<<' ';
    // cout<<endll;
    // exit(0);
}
signed main()
{
    euler();
   #ifndef ONLINE_JUDGE
   //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}