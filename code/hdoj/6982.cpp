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
const int maxn = 1100;
struct node{
    int u,v,w;
    bool fl;
    node(int a,int b,int c,int d):u(a),v(b),w(c),fl(d){}
    node(){}
    bool operator<(node a){
        if(w==a.w)
            return fl<a.fl;
        else return w<a.w;
        // return true;
    }
}bl[210000],wi[210000];
node egs[210000];
int tail=0;
int ans[maxn];
int fa[maxn];
int sum[maxn];
int l[maxn],r[maxn];
inline void dsu_init(int n){for(int i=1;i<=n;i++)fa[i]=i;}
int find(int x){if(fa[x]^x)return fa[x]=find(fa[x]);return x;}
void merge(int a,int b){fa[find(a)]=find(b);}
bool cmp(node a,node b){
    if(a.w==b.w)
        return a.fl> b.fl;
    else return a.w<b.w;
}
void work()
{
    tail=0;
    int n,m;
    cin>>n>>m;
    int u,v,d,c;
    for(int i=1;i<=m;i++){
        cin>>u>>v>>d>>c;
        bl[i]=node(u,v,d,0);
        wi[i]=node(u,v,c,1);
    }
    sort(bl+1,bl+m+1);
    dsu_init(n);
    int aa=0;
    for(int i=1;i<=m;i++){
        if(find(bl[i].v)==find(bl[i].u))
            continue;
        egs[++tail]=bl[i];
        merge(bl[i].v,bl[i].u);
        aa+=bl[i].w;
    }
    ans[0]=aa;
    sort(wi+1,wi+m+1);
    aa=0;
    dsu_init(n);
    for(int i=1;i<=m;i++){
        if(find(wi[i].u)==find(wi[i].v))
            continue;
        egs[++tail]=wi[i];
        merge(wi[i].v,wi[i].u);
        aa+=wi[i].w;
    }
    ans[n-1]=aa;
    int jia=0;
    for(int cc=0;cc<=1000;cc++){
        if(cc!=0)
            for(int i=1;i<=tail;i++)
                egs[i].w+=egs[i].fl;
        sort(egs+1,egs+tail+1);
        dsu_init(n);
        for(int i=1;i<=tail;i++){
            if(find(egs[i].u)==find(egs[i].v))
                continue;
            sum[cc]+=egs[i].w;
            l[cc]+=egs[i].fl;
            merge(egs[i].u,egs[i].v);
        }
        sort(egs+1, egs+1+tail, cmp);
        dsu_init(n);
        for(int i=1;i<=tail;i++){
            if(find(egs[i].u)==find(egs[i].v))
                continue;
            r[cc]+=egs[i].fl;
            merge(egs[i].u,egs[i].v);
        }
    }
    for(int k=1;k<n-1;k++){
        for(int i=0;i<=1000;i++){
            if(l[i]<=k&&r[i]>=k){
                ans[k]=sum[i]-k*i;
                break;
            }
        }
    }
    for(int i=0;i<=n-1;i++){
        // print(ans[i]);
        cout<<ans[i]<<endll;
    }
    // flush();
}
inline double run_time(){
    return 1.0*clock()/CLOCKS_PER_SEC;
}
signed main()
{
    freopen("1010.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin>>t;
    // read(t);
    // t=1;
    while (t--)
    {
        work();
    }
    cout<<run_time()<<endll;
    return 0;
}