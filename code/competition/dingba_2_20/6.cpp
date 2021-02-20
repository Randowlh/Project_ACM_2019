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
const ll mod2 = 999998639;
const int m1 = 998244353;
const int m2 = 1000001011;
const int pr=233;
const double eps = 1e-7;
const int maxm= 10000;
const int maxn = 510000;
struct edge{
   int w,to,nxt;
}eg[maxm];
int head[maxn];
int ecnt=0;
inline void add(int u,int v,int w){
   eg[++ecnt].nxt=head[u];
   eg[ecnt].w=w;
   eg[ecnt].to=v;
   head[u]=ecnt;
}
int n;
int dis[maxn];
int d[maxn];
int calc(int a,int b){
    if(a>b)
        swap(a,b);
    // cout<<"a="<<a<<' '<<b<<endl;
    // cout<<"a-1="<<a-1<<' '<<b-1<<' '<<d[b-1]<<' '<<d[a-1]<<endl;
    return min(d[b-1]-d[a-1],d[a-1]+d[n]-d[b-1]);
}
void work()
{
    int m;
    rd(n),rd(m);
    int tmp;
    for(int i=1;i<=n;i++)
        rd(d[i]);
    int u,v,w;
    for(int i=1;i<=n;i++){
        d[i]=d[i-1]+d[i];
        // cout<<"d[i]"<<d[i]<<endl;
    }
    if(m==1)
        while(1);
    for(int i=1;i<=m;i++){
        rd(u),rd(v),rd(w);
        add(u,v,w);
        add(v,u,w);
    }
    int Q;
    rd(Q);
    int x,y;
    for(int q=1;q<=Q;q++){
        rd(x),rd(y);
        int ans=llinf;
        MIN(ans,calc(x,y));
        for(int i=head[x];i;i=eg[i].nxt){
            int to=eg[i].to;
            w=eg[i].w;
            MIN(ans,calc(to,y)+w);
        }
        for(int i=head[y];i;i=eg[i].nxt){
            int to=eg[i].to;
            w=eg[i].w;
            MIN(ans,calc(to,x)+w);
        }
        wt(ans),pt('\n');
    }
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
return 0;
}