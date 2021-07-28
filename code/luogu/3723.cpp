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
const int maxn = 410000;
const int SIZE=(1<<21)+5;
const double PI=acos(-1);
struct CP{
    double x,y;
    CP(double x=0,double y=0):x(x),y(y){}
    CP operator +(const CP &A)const{return CP(x+A.x,y+A.y);}
    CP operator -(const CP &A)const{return CP(x-A.x,y-A.y);}
    CP operator *(const CP &A)const{return CP(x*A.x-y*A.y,x*A.y+y*A.x);}
};
int limit,rev[SIZE];
void DFT(CP *F,int op){
    for(int i=0;i<limit;i++)if(i<rev[i])swap(F[i],F[rev[i]]);
    for(int mid=1;mid<limit;mid<<=1){
        CP wn(cos(PI/mid),op*sin(PI/mid));
        for(int len=mid<<1,k=0;k<limit;k+=len){
            CP w(1,0);
            for(int i=k;i<k+mid;i++){
                CP tmp=w*F[i+mid];
                F[i+mid]=F[i]-tmp;
                F[i]=F[i]+tmp;
                w=w*wn;
            }
        }
    }
    if(op==-1)for(int i=0;i<limit;i++)F[i].x/=limit;
}
void FFT(int n,int m,CP *F,CP *G){
    for(limit=1;limit<=n+m;limit<<=1);
    for(int i=0;i<limit;i++)rev[i]=(rev[i>>1]>>1)|((i&1)?limit>>1:0);
    DFT(F,1),DFT(G,1);
    for(int i=0;i<limit;i++)F[i]=F[i]*G[i];
    DFT(F,-1);
}
CP a[maxn],b[maxn];
// int aa[maxn];
void work()
{
    int tmp;
    int n,m;
    cin>>n>>m;
    int a2=0,b2=0,a1=0,b1=0;
    for(int i=1;i<=n;i++){
        cin>>tmp;
        a[i].x=tmp;
        a1+=tmp*tmp;
        a2+=tmp;
        a[i+n].x=tmp;
    }
    for(int i=1;i<=n;i++){
        cin>>tmp;
        b[i].x=tmp;
        b1+=tmp*tmp;
        b2+=tmp;
    }
    reverse(b+1,b+n+1);
    FFT(n*2+10,n+10,a,b);
    int ans=0;
    // for(int i=1;i<=n;i++){
    //     for(int j=-m;j<=m;j++){
    //         ans=min(ans,a1+b1+j*j*n+2ll*j*(a2-b2)-2ll*(ll)a[i+n].x);
    //     }
    // }
    for(int i=n+1;i<=2*n;i++)
        MAX(ans,(int)(a[i].x+0.5));
    int taa=llinf;
    for(int i=-m;i<=m;i++)
        MIN(taa,a1+b1+i*i*n+2*i*(a2-b2));
    cout<<taa-2*ans<<endll;
}
signed main()
{
//    #ifndef ONLINE_JUDGE
//    freopen("in.txt","r",stdin);
//     freopen("out.txt","w",stdout);
// #endif
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}