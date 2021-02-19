#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=310000;
#define inf 0x7FFFFFFF
struct LCF
{
    struct Edge
    {
        int from;
        int to;
        int flow;
        int cost;
        Edge(int fr, int t, int f, int cc) : from(fr), to(t), flow(f), cost(cc) {}
    };
    int book[maxn];
    int dis[maxn];
    int n, m, s, t, ans = 0;
    vector<Edge> edge;
    vector<int> mp[maxn];
    void add_edge(int x, int y, int flow, int cost)
    {
        edge.push_back(Edge(x, y, flow, cost));
        edge.push_back(Edge(y, x, 0, -cost));
        mp[x].push_back(edge.size() - 2);
        mp[y].push_back(edge.size() - 1);
    }
    inline bool spfa()
    {
        for (int i = 0; i <= n; i++)
        {
            dis[i] = inf;
            book[i] = 0;
        }
        dis[t] = 0;
        book[t] = 1;
        deque<int> q;
        q.push_back(t);
        while (!q.empty())
        {
            int now = q.front();
            q.pop_front();
            for (int i = 0; i < mp[now].size(); i++)
            {
                int to = edge[mp[now][i]].to;
                if (edge[mp[now][i] ^ 1].flow && dis[to] > dis[now] - edge[mp[now][i]].cost)
                {
                    dis[to] = dis[now] - edge[mp[now][i]].cost;
                    if (!book[to])
                    {
                        book[to] = 1;
                        if (!q.empty() && dis[to] < dis[q.front()])
                            q.push_front(to);
                        else
                            q.push_back(to);
                    }
                }
            }
            book[now] = 0;
        }
        return dis[s] < inf;
    }
    int dfs(int x, int flow)
    {
        book[x] = 1;
        if (x == t)
        {
            return flow;
        }
        int used = 0, a;
        for (int i = 0; i < mp[x].size(); i++)
        {
            int to = edge[mp[x][i]].to;
            if (!book[to] && edge[mp[x][i]].flow && dis[x] - edge[mp[x][i]].cost == dis[to])
            {
                a = dfs(to, min(flow - used, edge[mp[x][i]].flow));
                if (a)
                    ans += a * edge[mp[x][i]].cost, edge[mp[x][i]].flow -= a, edge[mp[x][i] ^ 1].flow += a, used += a;
                if (used == flow)
                    break;
            }
        }
        return used;
    }
    inline int cost_flow()
    {
        int flow = 0;
        while (spfa())
        {
            memset(book, 0, sizeof(book));
            flow += dfs(s, inf);
        }
        return flow;
    }
} fl;
int tt[10];
signed main(){
    // freopen("in.txt","r",stdin);
    int n,m;
    scanf("%lld%lld",&n,&m);
    fl.s=0;
    fl.t=n+m+10;
    fl.n=n+m+100;
    for(int i=1;i<=m;i++)
        fl.add_edge(0,i,1,0);
    for(int i=m+1;i<=n+m;i++)
        fl.add_edge(i,n+m+10,1,0);
    int tmp;
    for(int i=1;i<=m;i++){
        int k;
        scanf("%lld",&k);
        for(int i=1;i<=k;i++)
            scanf("%lld",&tt[i]);
        int w;
        scanf("%lld",&w);
        for(int j=1;j<=k;j++)
            fl.add_edge(i,tt[j]+m,1,inf-w);
    }
    // cout<<0x3f3f3f3f<<endl;
    int aa=fl.cost_flow();
    printf("%lld\n",aa*inf-fl.ans);
}