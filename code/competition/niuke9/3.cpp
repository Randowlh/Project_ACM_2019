struct LCF
{
    struct Edge
    {
        int from;
        int to;
        char flow;
        char cost;
        Edge(int fr = 0, int t = 0, int f = 0, int cc = 0) : from(fr), to(t), flow(f), cost(cc) {}
    };
#define inf 0x3f3f3f3f
#define maxn ((1<<20)+5)
    bool book[maxn];
    unsigned char dis[maxn];
    int n, s, t, ans;
    vector<Edge> edge;
    vector<int> mp[maxn];
    void add_edge(int x, int y, int flow, int cost)
    {
        edge.push_back(Edge(x, y, flow, cost));
        edge.push_back(Edge(y, x, 0, -cost));
        mp[x].push_back(edge.size() - 2);
        mp[y].push_back(edge.size() - 1);
    }
    bool spfa()
    {
        for (int i = 0; i <= n; i++)
        {
            dis[i] = 200;
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
            return flow;
        int used = 0, a;
        for (int i = 0; i < mp[x].size(); i++)
        {
            int to = edge[mp[x][i]].to;
            if (!book[to] && edge[mp[x][i]].flow > 0 && dis[x] - edge[mp[x][i]].cost == dis[to])
            {
                a = dfs(to, min(flow - used,(int) edge[mp[x][i]].flow));
                if (a)
                    ans += a * edge[mp[x][i]].cost, edge[mp[x][i]].flow -= a, edge[mp[x][i] ^ 1].flow += a, used += a;
                if (used == flow)
                    break;
            }
        }
        return used;
    }
    void init(int tn, int ts, int tt)
    {
        for (int i = 0; i <= tn ; i++)
            mp[i].clear();
        edge.clear();
        n = tn;
        s = ts;
        t = tt;
        ans = 0;
    }
    int cost_flow()
    {
        int flow = 0;
        while (spfa())
        {
            for (int i = 0; i <= n; i++)
                book[i] = 0;
            flow += dfs(s, inf);
        }
        return flow;
    }
} tmp;