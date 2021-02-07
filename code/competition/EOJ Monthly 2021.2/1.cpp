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
const ll mod = llinf;
const ll mod2 = 999998639;
const int m1 = 998244353;
const int m2 = 1000001011;
const int pr=233;
const double eps = 1e-7;
const int maxm= 1;
const int maxn = 51000;
int n, m;
vector<int> mp[maxn];
int cnt = 0;
int rk[maxn];
int dfn[maxn], chu[maxn];
int root;
int len;
int d[maxn], pre[maxn][30], h[maxn];
struct nod
{
    int x, y, gg;
}b[maxn<<1];
void ins(int x, int y)
{
    len++;
    b[len].x = x;
    b[len].y = y;
    b[len].gg = h[x];
    h[x] = len;
}
void dfs(int x) 
{
    for(int i = h[x]; i > 0; i = b[i].gg)
    {
        int y = b[i].y;
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
    date[pos].v = date[lson(pos)].v;
    date[pos].v += date[rson(pos)].v;
}
inline void pushdown(int pos)
{
    if (!date[pos].lazy)
        return;
    date[lson(pos)].lazy += date[pos].lazy;
    date[rson(pos)].lazy += date[pos].lazy;
    date[rson(pos)].v += date[pos].lazy * (date[rson(pos)].r - date[rson(pos)].l + 1) % mod;
    date[lson(pos)].v += date[pos].lazy * (date[lson(pos)].r - date[lson(pos)].l + 1) % mod;
    date[pos].lazy = 0;
}
void build(int pos, int l, int r)
{
    if (l == r)
    {
        date[pos].set(0, l, r);
        return;
    }
    date[pos].set(0, l, r);
    int mid = (l + r) >> 1;
    build(lson(pos), l, mid);
    build(rson(pos), mid + 1, r);
    pushup(pos);
}
void update(int pos, int l, int r, int v)
{
    if (date[pos].l >= l && date[pos].r <= r)
    {
        date[pos].lazy += v;
        date[pos].v += (date[pos].r - date[pos].l + 1) * v;
        return;
    }
    int mid = (date[pos].l + date[pos].r) >> 1;
    pushdown(pos);
    if (l <= mid)
        update(lson(pos), l, r, v);
    if (r >= mid + 1)
        update(rson(pos), l, r, v);
    pushup(pos);
}
int query(int pos, int l, int r)
{
    if (date[pos].l >= l && date[pos].r <= r)
        return date[pos].v;
    pushdown(pos);
    int ans = 0;
    int mid = (date[pos].l + date[pos].r) >> 1;
    if (l <= mid)
        ans += query(lson(pos), l, r);
    if (r >= mid + 1)
        ans += query(rson(pos), l, r);
    ans %= mod;
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
inline void tree_path_update(int u, int v, int w)
{
    while (tree[u].top != tree[v].top)
    {
        if (tree[tree[u].top].depth < tree[tree[v].top].depth)
            swap(u, v);
        update(1, dfn[tree[u].top], dfn[u], w);
        u = tree[tree[u].top].fa;
    }
    if (tree[u].depth < tree[v].depth)
        swap(u, v);
    update(1, dfn[v], dfn[u], w);
}
inline int tree_path_sum(int u, int v)
{
    int tol = 0;
    while (tree[u].top != tree[v].top)
    {
        if (tree[tree[u].top].depth < tree[tree[v].top].depth)
            swap(u, v);
        tol += query(1, dfn[tree[u].top], dfn[u]);
        tol %= mod;
        u = tree[tree[u].top].fa;
    }
    if (tree[u].depth < tree[v].depth)
        swap(u, v);
    tol += query(1, dfn[v], dfn[u]);
    tol %= mod;
    return tol;
}
struct egs{
    int u,v,w;
};
vector<egs> vv;
void work()
{
    rd(n);
    int u,v,w;
    for(int i=1;i<=n-1;i++){
        rd(u),rd(v),rd(w);
        u++,v++;
        ins(u,v);
        ins(v,u);
        mp[u].push_back(v);
        mp[v].push_back(u);
        vv.push_back((egs){u,v,w});
    }
    d[1]=1;
    pre[1][0]=0;
    dfs(1);
    for(int i=1; i<=20; i++)
        for(int x=1; x<=n; x++)
            pre[x][i] = pre[pre[x][i-1]][i-1];
    tree_build(1,1);
    tree_decomposition(1,1);
    build(1, 1, n);
    for(int i=0;i<vv.size();i++){
        if(tree[vv[i].u].depth>tree[vv[i].v].depth)
            update(1,dfn[vv[i].u],dfn[vv[i].u],vv[i].w);
        else
            update(1,dfn[vv[i].v],dfn[vv[i].v],vv[i].w);
    }
    // for(int i=1;i<=n;i++){
    //     cout<<tree_path_sum(i,i)<<endl;
    // }
    int q,tmp;
    rd(q);
    for(int tt=1;tt<=q;tt++){
        set<int> s;
        for(int i=1;i<=5;i++){
            rd(tmp);
            tmp++;
            s.insert(tmp);
        }
        int ans=0;
        while(s.size()!=1){
            vector<pair<int,pair<int,int>>> tta;
            for(auto i=s.begin();i!=s.end();i++){
                auto j=i;
                j++;
                while(j!=s.end()){
                    tta.push_back(make_pair(n-tree[lca(*i,*j)].depth,make_pair(*i,*j)));
                    j++;
                }
            }
            sort(tta.begin(),tta.end());
            int lla=lca(tta[0].second.first,tta[0].second.second);
            ans+=tree_path_sum(tta[0].second.first,tta[0].second.second);
            ans-=query(1,dfn[lla],dfn[lla]);
            s.erase(tta[0].second.first),s.erase(tta[0].second.second);
            s.insert(lla);
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