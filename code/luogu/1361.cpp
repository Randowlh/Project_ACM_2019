#include <bits/stdc++.h>
#include<cstdio>
#include<iostream>
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
const ll mod = (0 ? 1000000007 : 998244353);
const ll mod2 = 999998639;
const int m1 = 998244353;
const int m2 = 1000001011;
const int pr=233;
const double eps = 1e-7;
const int maxm= 100000;
const int maxn = 11000;
/*
class DC{
public:
    struct Edge
   {
        int from,to,flow,cap;
        Edge(int fr, int t, int f, int c) : from(fr), to(t), flow(f), cap(c) {}
    };
    bool book[maxn];
    int cur[maxn],depth[maxn],n, t, s;
    vector<Edge> edge;
    vector<int> mp[maxn];
    int bfs(int s, int t)
    {
        for(int i=0;i<=n;i++)
            book[i]=0;
        queue<int> q;
        q.push(s);
        book[s] = 1;
        depth[s] = 0;
        while (!q.empty())
        {
            int now = q.front();
            q.pop();
            for (int i = 0; i < mp[now].size(); i++)
            {
                Edge &e = edge[mp[now][i]];
                if (!book[e.to] && e.cap > e.flow)
                {
                    depth[e.to] = depth[e.from] + 1;
                    book[e.to] = 1;
                    q.push(e.to);
                }
            }
        }
        return book[t];
    }
    int dfs(int now, int a)
    {
        if (now == t || a == 0)
            return a;
        int flow = 0;
        int f;
        for (int &i = cur[now]; i < mp[now].size(); i++)
        {
            Edge &e = edge[mp[now][i]];
            if (depth[now] + 1 == depth[e.to] && (f = dfs(e.to, min(a, e.cap - e.flow))) > 0)
            {
                e.flow += f;
                flow += f;
                edge[mp[now][i] ^ 1].flow -= f;
                a -= f;
                if (a == 0)
                    break;
            }
        }
        return flow;
    }
    int Dinic()
    {
        int ans = 0;
        while (bfs(s, t))
        {
            for(int i=0;i<=n;i++)
                cur[i]=0;
            ans += dfs(s, 0x7FFFFFFF);
        }
        return ans;
    }
    void add_edge(int from, int to, int cap)
    {
        edge.push_back(Edge(from, to, 0, cap));
        edge.push_back(Edge(to, from, 0, 0));
        mp[from].push_back(edge.size() - 2);
        mp[to].push_back(edge.size() - 1);
    }
    void init(int ss,int tt,int nn){
        s=ss,t=tt,n=nn;
        for(int i=0;i<=n;i++)
            mp[i].clear();
        edge.clear();
    }
} */
class DC{
    public:
    int dfs(int now,int a){
        if(now==t||a==0)
            return a;
        int flow=0;
        int f;
        for(int &i=cur[now];i<mp[now].size();i++){
            eg &e=edge[mp[now][i]];
            if(dep[now]+1==dep[e.to]&&(f=dfs(e.to,min(a ,e.cap-e.flow))>0)){
                e.flow+=f;
                flow += f;
                edge[mp[now][i]^1].flow-=f;
                a-=f;
                if(a==0)
                    break;
            }
        }
        return flow;
    }
    int Dinic(){
        int ans=0;
        while(bfs(s,t)){
            for(int i=0;i<=n;i++)
                cur[i]=0;
            ans+=dfs(s,inf);
        }
    return ans;
    }
    void add_edge(int fr,int to,int cap){
        edge.push_back(eg(fr,to,0,cap));
        edge.push_back(eg(to,fr,0,0));
        mp[fr].push_back(edge.size()-2);
        mp[to].push_back(edge.size()-1);
    }
    void init(int ss,int tt,int nn){
        s=ss,t=tt,n=nn;
        for(int i=0;i<=n;i++)
            mp[i].clear();
        edge.clear();
    }
}dc;
int n;
void work()
{
    rd(n);
    dc.init(0,n+2010,n+2100);
    int tmp;
    int tt=0;
    for(int i=1;i<=n;i++){
        rd(tmp);
        tt+=tmp;
        dc.add_edge(0,i,tmp);
    }
    for(int i=1;i<=n;i++){
        rd(tmp);
        tt+=tmp;
        dc.add_edge(i,n+2010,tmp);
    }
    int m;
    rd(m);
    for(int i=1;i<=m;i++){
        int k,a,b;
        rd(k),rd(a),rd(b);
        tt+=a;
        tt+=b;
        dc.add_edge(0,n+i*2-1,a);
        dc.add_edge(n+i*2,n+2010,b);
        for(int j=1;j<=k;j++){
            rd(tmp);
            dc.add_edge(n+i*2-1,tmp,llinf);
            dc.add_edge(tmp,n+i*2,llinf);
        }
    }
    wt(tt-dc.Dinic()),pt('\n');
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