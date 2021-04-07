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
const int maxm= 410000;
const int maxn = 110000;
struct edge{
   int to,nxt;
}eg[maxm];
int head[maxn];
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
int dep[maxn],du[maxn];
int u[maxm],v[maxm];
bool mad[maxn];
int dfs(int pos){
    if(mad[pos])
        return 0;
    int ans=1;
    mad[pos]=1;
    for(int i=head[pos];i;i=eg[i].nxt){
        int to=eg[i].to;
        if(dep[to]==dep[pos]+1)
            if(du[to]>1)
                du[to]--;
            else
                ans+=dfs(to);
    } 
    return ans;
}
struct cmp{
    bool operator()(int a,int b){
        return dep[a]>dep[b];
    }
};
void work()
{
    int n,m,q;
    rd(n),rd(m),rd(q);
    for(int i=1;i<=m;i++){
        rd(u[i]),rd(v[i]);
        add(u[i],v[i]);
        add(v[i],u[i]);
    }
    yx_queue<int,vector<int>, cmp>qu;
    qu.push(1);
    dep[1]=1;
    while(!qu.empty()){
        int t=qu.top();
        qu.pop();
        for(int i =head[t];i;i=eg[i].nxt){
            int to=eg[i].to;
            if(!dep[to]){
                du[to]=1;
                dep[to]=dep[t]+1;
                qu.push(to);
            }else if(dep[to]==dep[t]+1)
                du[to]++;
        }
    }
    int aa=0;
    int opt;
    for(int i=1;i<=q;i++){
        rd(opt);
        if(dep[u[opt]]<dep[v[opt]])
            swap(u[opt],v[opt]);
        if(du[u[opt]]>1)
            du[u[opt]]--;
        else
            aa+=dfs(u[opt]);
        wt(aa),pt('\n');
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