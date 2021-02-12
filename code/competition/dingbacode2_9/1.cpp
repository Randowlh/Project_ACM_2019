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
const ll mod2 = 999998639;
const int m1 = 998244353;
const int m2 = 1000001011;
const int pr=233;
const double eps = 1e-7;
const int maxm= 410000;
const int maxn = 110000;
int n, m;
vector<int> mp[maxn];
int cnt = 0;
int rk[maxn];
int dfn[maxn], chu[maxn],rvs[maxn],dd[maxn];
int root;
struct seg
{
    int v;
    int l;
    int r;
    int lazy;
    inline void set(int a = 0, int b = 0, int c = 0, int d = 0) { v = a, l = b, r = c, lazy = d; }
} date[4 * maxn + 100];
inline void pushup(int pos)
{
    date[pos].v = max(date[lson(pos)].v,date[rson(pos)].v);
}
void build(int pos, int l, int r)
{
    if (l == r)
    {
        date[pos].set(dd[rvs[l]], l, r);
        return;
    }
    date[pos].set(0, l, r);
    int mid = (l + r) >> 1;
    build(lson(pos), l, mid);
    build(rson(pos), mid + 1, r);
    pushup(pos);
}
void update(int pos,int x,int v){
    if(date[pos].l==date[pos].r){
        date[pos].v=v;
        return;
    }
    int mid=(date[pos].r+date[pos].l)>>1;
    if(x<=mid)
        update(lson(pos),x,v);
    else update(rson(pos),x,v);
    pushup(pos);
}
int query(int pos, int l, int r)
{
    if(l>r)
        return 0;
    if (date[pos].l >= l && date[pos].r <= r)
        return date[pos].v;
    int ans = 0;
    int mid = (date[pos].l + date[pos].r) >> 1;
    if (l <= mid)
        MAX(ans,query(lson(pos), l, r));
    if (r >= mid + 1)
        MAX(ans,query(rson(pos), l, r));
    return ans;
}
struct node
{
    int depth, top, sz, fa, hson;
    node(int a = 0, int b = 0, int c = 0, int d = 0, int e = 0) : depth(a), top(b), sz(c), fa(d), hson(e) {}
    inline void init() { depth = 0, top = 0, sz = 0, fa = 0, hson = 0; }
} tree[maxn];
int tree_build(int x, int dep)
{
    tree[x].hson = 0;
    tree[x].depth = dep;
    tree[x].sz = 1;
    for (int i = 0; i < mp[x].size(); i++)
    {
        if (mp[x][i] == tree[x].fa)
            continue;
        tree[mp[x][i]].fa = x;
        tree[x].sz += tree_build(mp[x][i], dep + 1);
        if (tree[mp[x][i]].sz > tree[tree[x].hson].sz)
            tree[x].hson = mp[x][i];
    }
    return tree[x].sz;
}
void tree_decomposition(int x, int top)
{
    tree[x].top = top;
    cnt++;
    dfn[x] = cnt;
    rvs[cnt]=x;
    rk[cnt] = x;
    if (tree[x].hson == 0)
    {
        chu[x] = cnt;
        return;
    }
    tree_decomposition(tree[x].hson, top);
    for (int i = 0; i < mp[x].size(); i++)
    {
        if (mp[x][i] != tree[x].hson && mp[x][i] != tree[x].fa)
        {
            tree_decomposition(mp[x][i], mp[x][i]);
        }
    }
    chu[x] = cnt;
}
inline int tree_path_sum(int u, int v)
{
    int tol = 0;
    while (tree[u].top != tree[v].top)
    {
        if (tree[tree[u].top].depth < tree[tree[v].top].depth)
            swap(u, v);
        MAX(tol,query(1, dfn[tree[u].top], dfn[u]));
        u = tree[tree[u].top].fa;
    }
    if (tree[u].depth < tree[v].depth)
        swap(u, v);
    MAX(tol,query(1, dfn[v], dfn[u]));
    return tol;
}
int fa[maxn];
int find(int x){
    if(x==fa[x])
        return x;   
    return fa[x]=find(fa[x]);
}
void merge(int a,int b){
    int l=find(a);
    int r=find(b);
    if(l!=r)
        fa[l]=r;
}
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
inline void cl(int n){
    for(int i=0;i<=n;i++)
        head[i]=0;
    ecnt=0;
}
struct egg{
    int u,v,w,cnt;
    inline bool operator<(egg a){ return w<a.w;}
}rod[maxm],rrod[maxm];
////////////////////////////////////////////////////////////////
int len;
int d[maxn], pre[maxn][30], h[maxn];

void dfs(int x) 
{
    for(int i = head[x]; i > 0; i = eg[i].nxt)
    {
        int y = eg[i].to;
        if(d[y] == 0)
        {
            d[y] = d[x] + 1;
            pre[y][0] = x; 
            dfs(y);
        }
    }
}
int lca(int x, int y) 
{
    if(d[x] < d[y]) swap(x,y);
    for(int i=20; i>=0; i--) 
    {
        if(d[pre[x][i]] >= d[y])
        {
            x = pre[x][i];
        }
    }
    if(x == y) return x;
    for(int i=20; i>=0; i--)
    {
        if(pre[x][i] != pre[y][i]) 
        {               
            x = pre[x][i];
            y = pre[y][i];
        }
    }
    return pre[x][0];
}
////////////////////////////////////////////////////////////////
bool ff[maxm];
void ddfs(int pos,int fat){
    // cout<<"pos="<<pos<<' '<<fat<<endl;
    for(int i=head[pos];i;i=eg[i].nxt){
        int to=eg[i].to;
        if(to==fat)
            continue;
        dd[to]=eg[i].w;
        ddfs(to,pos);
    }
}
void work()
{
    rd(n),rd(m);
    int u,v,w;
    int ans=0;
    for(int i=1;i<=n;i++)
        fa[i]=i;
    for(int i=1;i<=m;i++){
        rd(rod[i].u),rd(rod[i].v),rd(rod[i].w),rod[i].cnt=i;
        rrod[i]=rod[i];
    }
    int cntt=0;
    sort(rod+1,rod+1+m);
    for(int i=1;i<=m;i++){
        if(find(rod[i].u)!=find(rod[i].v)){
            cntt++;
            ff[rod[i].cnt]=1;
            ans+=rod[i].w;
            add(rod[i].u,rod[i].v,rod[i].w);
            add(rod[i].v,rod[i].u,rod[i].w);
            mp[rod[i].u].push_back(rod[i].v);
            mp[rod[i].v].push_back(rod[i].u);
            merge(rod[i].u,rod[i].v);
        }
    }
    d[1]=1;
    pre[1][0]=0;
    dfs(1);
    for(int i=1; i<=20; i++)
        for(int x=1; x<=n; x++)
            pre[x][i] = pre[pre[x][i-1]][i-1];
    ddfs(1,-1);
    tree_build(1,1);
    tree_decomposition(1,1);
    build(1, 1, n);
    for(int i=1;i<=m;i++)
        rod[i]=rrod[i];
    for(int i=1;i<=m;i++){
        if(ff[i]){
            wt(ans),pt('\n');
            continue;
        }
        int tans=ans;
        if(dfn[rod[i].u]>dfn[rod[i].v])
            swap(rod[i].u,rod[i].v);
        int&u=rod[i].u,&v=rod[i].v;
        int tt=lca(u,v);
        int tmp=query(1,dfn[tt],dfn[tt]);
        update(1,dfn[tt],0);
        tans-=tree_path_sum(u,v);
        tans+=rod[i].w;
        update(1,dfn[tt],tmp);
        wt(tans),pt('\n');
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