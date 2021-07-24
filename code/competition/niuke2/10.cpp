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
const double eps = 1e-7;
const int maxm= 410000;
const int maxn = 210000;
struct edge{
   int to,nxt;
}eg[maxm];
int now[maxn];
int maa[450];
int lastedt[maxn];
int ans[maxn];
int pre[maxn];
bool flag[maxn];
int head[maxn];
int du[maxn];
int belong[maxn];
int blk=447;
int w[450][10010];
// vector<pair<int,int>> tt[450];  
vector<int> mp[450];
int ecnt=0;
inline void add(int u,int v){
   eg[++ecnt].nxt=head[u];
   eg[ecnt].to=v;
   head[u]=ecnt;
}
inline void cl(int n){
    for(int i=0;i<=n;i++)
        head[i]=0;
    ecnt=0;
}
void work()
{
    int n,m,q;
    read(n,m,q);
    int u,v;
    for(int i=1;i<=m;i++){
        read(u,v);
        add(u,v);
        add(v,u);
        du[u]++;du[v]++;
    }
    int tail=0;
    for(int i=1;i<=n;i++)
        if(du[i]>blk)
            belong[i]=++tail;
    for(int i=1;i<=n;i++){
        // pre[i]=1;
        if(du[i]<=blk)
            continue;
        for(int j=head[i];j;j=eg[j].nxt){
            int to=eg[j].to;
            if(du[to]<=blk)
                continue;
            mp[belong[i]].push_back(to);
        }
    }
    for(int i=1;i<=q;i++){
        int pos,val;
        read(pos,val);
        if(du[pos]>blk){
            for(int j=now[pos]+1;j<=now[pos]+val;j++)
                w[belong[pos]][j]=i;
            for(int j=0;j<mp[belong[pos]].size();j++){
                int to=mp[belong[pos]][j];
                MAX(maa[to],now[pos]+val);
                if(flag[to]){
                    if(now[to]<=now[pos]+val){
                        flag[to]=0;
                        ans[to]+=i-pre[to];      
                    }
                }
            }
            now[pos]+=val;
            if(maa[pos]<now[pos]&&flag[pos]==0){
                flag[pos]=1;
                pre[pos]=i;
            } 
        }else{
            int mi=llinf;
            for(int j=head[pos];j;j=eg[j].nxt){
                int to=eg[j].to;
                MAX(maa[to],now[pos]+val);
                MAX(maa[pos],now[to]);
                if(du[to]>blk){
                    int t=w[belong[to]][now[pos]];
                    if(t!=0)
                        MIN(mi,t);
                }
                if(now[to]<=now[pos]+val&&flag[to]){
                    if(du[to]<=blk){
                        if(!lastedt[to])
                            lastedt[to]=i;
                    }else{
                        flag[to]=0;
                        ans[to]=i-pre[to];
                    }
                }
            }
            if(flag[pos]&&(lastedt[pos]||mi!=llinf)){
                if(!lastedt[pos])
                    lastedt[pos]=llinf;
                int pr=min(mi,lastedt[pos]);
                ans[pos]+=pr-pre[pos];
                flag[pos]=0;
                lastedt[pos]=0;
            }
            now[pos]+=val;
            if(maa[pos]<now[pos]&&flag[pos]==0){
                flag[pos]=1;
                pre[pos]=i;
                lastedt[pos]=0;
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(flag[i]){
            if(du[i]>blk){
                ans[i]+=q-pre[i];
            }else{
                int mi=llinf;
                for(int j=head[i];j;j=eg[j].nxt){
                    int to=eg[j].to;
                    if(du[to]<=blk)
                        continue;
                    int t=w[belong[to]][now[i]];
                    if(t!=0)
                        MIN(mi,t);
                }
                if(!lastedt[i])
                    lastedt[i]=llinf;
                ans[i]+=min(q,min(mi,lastedt[i]))-pre[i];
            }
        }
    }
    for(int i=1;i<=n;i++)
        print(ans[i]);
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
    {
        work();
    }
    flush();
    return 0;
}