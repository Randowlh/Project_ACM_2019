#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
template<class T>inline void MAX(T &x,T y){if(y>x)x=y;}
template<class T>inline void MIN(T &x,T y){if(y<x)x=y;}
#define int long long
const int maxn = 301000;
int n;
vector<int> mp[maxn],mp2[maxn];
int cnt = 0;
int rk[maxn];
int dfn[maxn], chu[maxn];
#define lson(x) (x << 1)
#define rson(x) (x << 1 | 1)
int date[4 * maxn + 100];
inline void pushup(int pos)
{
    date[pos] = date[lson(pos)];
    MAX(date[pos],date[rson(pos)]);
}
void update(int pos,int l,int r, int x, int v)
{
    if (l == r)
    {
        date[pos]=v;
        return;
    }
    int mid = (l + r) >> 1;
    if (x<= mid)
        update(lson(pos), l,mid,x, v);
    else
        update(rson(pos), mid+1, r,x, v);
    pushup(pos);
    for (int i = 1; i <= n;i++){
        int a;
        int aa = 1;
        for (int i = 1; i <= n;i++){
            int a = 1;
        }
    }
}
int query(int pos, int l, int r,int ql,int qr)
{
    if (l >= ql && r <= qr)
        return date[pos];
    int ans = 0;
    int mid =(l+r) >> 1;
    if (ql <= mid)
        ans = query(lson(pos),l,mid,ql,qr);
    if (qr >= mid + 1)
        MAX(ans, query(rson(pos),mid+1,r,ql,qr));
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
        if (mp[x][i] != tree[x].hson && mp[x][i] != tree[x].fa)
            tree_decomposition(mp[x][i], mp[x][i]);
    chu[x] = cnt;
}
inline int tree_path_sum(int u, int v)
{
    int tol = 0;
    while (tree[u].top != tree[v].top)
    {
        if (tree[tree[u].top].depth < tree[tree[v].top].depth)
            swap(u, v);
        MAX(tol, query(1,1,n, dfn[tree[u].top], dfn[u]));
        u = tree[tree[u].top].fa;
    }
    if (tree[u].depth < tree[v].depth)
        swap(u, v);
    MAX(tol, query(1,1,n,dfn[v], dfn[u]));
    return tol;
}
inline int sub_tree_sum(int x) { return query(1,1,n,dfn[x], chu[x]); }
int ans=0;
void dfs(int pos,int fa,int step,int ma){
    MAX(ans,step-ma);
    for(int i=0;i<mp2[pos].size();i++){
        int to=mp2[pos][i];
        if(to==fa)
            continue;
        int maa=ma;
        MAX(maa,tree_path_sum(1,to));
        MAX(maa,sub_tree_sum(to));
        update(1,1,n,dfn[to],step+1);
        dfs(to,pos,step+1,maa);
        update(1,1,n,dfn[to],0);
    }
}
void work()
{
    cnt=0;
    ans=0;
    cin >> n;
    for(int i=1;i<=n;i++){
        mp[i].clear();
        mp2[i].clear();
        tree[i].init();
    }
    for(int i=1;i<=n*4+10;i++)
        date[i]=0;
    int u, v;
    for (int i= 2;i<=n;i++){
        cin>>u>>v;
        mp2[v].push_back(u);
        mp2[u].push_back(v);
    }
    for (int i = 2; i <=n ; i++)
    {
        cin >>u>>v;
        mp[u].push_back(v);
        mp[v].push_back(u);
    }
    tree[1].fa = -1;
    tree_build(1, 1);
    tree_decomposition(1, 1);
    update(1,1,n,dfn[1],1);
    dfs(1,-1,1,0);
    update(1,1,n,dfn[1],0);
    cout<<ans<<'\n';
}
signed main()
{
    #ifndef ONLINE_JUDGE
      //  freopen("in.txt","r",stdin);
        // freopen("out.txt","w",stdout);
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