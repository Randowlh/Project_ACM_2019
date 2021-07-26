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
const ll llinf = 4223372036854775807;
const ll mod = (0 ? 1000000007 : 998244353);
ll pow(ll a,ll b,ll md=mod) {ll res=1;a%=md; assert(b>=0); for(;b;b>>=1){if(b&1)res=mul(res,a,md);a=mul(a,a,md);}return res;}
const ll mod2 = 999998639;
const int m1 = 998244353;
const int m2 = 1000001011;
const int pr=233;
const double eps = 1e-10;
const int maxm= 1;
const int maxn = 110000;
template<class T>inline void rd(T &x){
   x=0;char o,f=1;
   while(o=getchar(),o<48)if(o==45)f=-f;
   do x=(x<<3)+(x<<1)+(o^48);
   while(o=getchar(),o>47);
   x*=f;
}
int n,m,x,y;
int a[maxn],b[maxn];
double pre[maxn];
bool ck(double avr,int flag){
    if(flag){
        for(int i=1;i<=n;i++){
            pre[i]=a[i]-avr;
            pre[i]=pre[i-1]+pre[i];
        }
        double now=llinf;
        for(int i=x;i<=n;i++){
            MIN(now,pre[i-x]);
            if(pre[i]-now>=0)
                return true;
        }
        return false;
    }else{
        for(int i=1;i<=m;i++){
            pre[i]=b[i]-avr;
            pre[i]=pre[i-1]+pre[i];
        }
        double now=llinf;
        for(int i=y;i<=m;i++){
            MIN(now,pre[i-y]);
            if(pre[i]-now>=0)
                return true;
        }
        return false;
    }
}
void work()
{
    rd(n),rd(m),rd(x),rd(y);
    for(int i=1;i<=n;i++)
        rd(a[i]);
    for(int i=1;i<=m;i++)
        rd(b[i]);
    double ans=0;
    double l=0,r=maxn;
    while(abs(r-l)>=eps){
        double mid=(l+r)/2;
        if(ck(mid,1))
            l=mid;
        else r=mid; 
    }
    ans+=l;
    l=0;r=maxn;
    while(abs(r-l)>=eps){
        double mid=(l+r)/2;
        if(ck(mid,0))
            l=mid;
        else r=mid; 
    }
    ans+=l;
    printf("%.10lf\n",ans);
}
signed main()
{
   #ifndef ONLINE_JUDGE
   freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif
    // std::ios::sync_with_stdio(false);
    // cin.tie(NULL);
    int t = 1;
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}