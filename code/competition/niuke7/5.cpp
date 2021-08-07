#include <bits/stdc++.h>
 
using namespace std;
 
const int maxn = 3e5 + 10;
vector<int> g1[maxn], g2[maxn];
int n, ret;
#define ls(x)   son[x][0]
#define rs(x)   son[x][1]
template<typename T, const size_t MAX = 300007>
class Link_Cut_Tree {
    public :
        // 点值与路径权值
        T val[MAX], sum[MAX];
        // 栈  splay要从上往下放标记， 所以单独开的栈来push_down
        int sta[MAX], top;
        inline void clear(int n) {
            for (int i = 0; i <= n; ++ i) {
                val[i] = sum[i] = 0;
                revtag[i] = 0;
                ls(i) = rs(i) = Fa[i] = 0;
            }
        }
        inline void Splay(int x) {
            int y = x;
            top = 0; sta[++ top] = y;
            while(!isroot(y)) {
                sta[++ top] = Fa[y];
                y = Fa[y];
            }
            while(top) push_down(sta[top --]);
            while(!isroot(x)) {
                y = Fa[x]; int z = Fa[y];
                if(!isroot(y)) Rotate((chk(x) ^ chk(y)) ? x : y);
                Rotate(x);
            }
        }
        // 换根  使x变成这个树的根
        // 森林 > 树 > 若干splay
        inline void makeroot(int x) {
            Access(x); Splay(x);
            Rev(x);
        }
        // 提取边  单独拎出来
    	// Split时反转y到了顶端  且更新好了  此时y储存的就是这条链信息
        inline void Split(int x, int y) {
            makeroot(x);
            Access(y); Splay(y);
        }
        // // 是否有边
        // inline bool islink(int x, int y) {
        //     makeroot(x);
        //     return findroot(y) == x && Fa[y] == x && !ls(y);
        // }
        // 连边
        inline void Link(int x, int y) {
            makeroot(x);
            // 写成 fa[x] = y 
            // 因为此时x是根  一定无父节点 所以不会出错
            if(findroot(y) != x) Fa[x] = y;
        }
        // 断边
        inline void cut(int x, int y) {
            makeroot(x);
            if(findroot(y) == x && Fa[y] == x && !ls(y)) {
                Fa[y] = rs(x) = 0;
                push_up(x);
            }
        }
    	// 维护信息
        inline void push_up(int x) {
            sum[x] = (sum[ls(x)] ^ sum[rs(x)] ^ val[x]);
        }
    private :
        int Fa[MAX], son[MAX][2], revtag[MAX];
        // 判断是否为 splay 的根  只需父亲节点不含这个儿子即可
        // 即父子边为虚
        inline bool isroot(int x) {
            return ls(Fa[x]) != x && rs(Fa[x]) != x;
        }
        // 换根后反转 splay 维持性质
        inline void Rev(int x) {
            swap(ls(x), rs(x));
            revtag[x] ^= 1;
        }
        // 下放标记
        inline void push_down(int x) {
            if(revtag[x]) {
                if(ls(x)) Rev(ls(x));
                if(rs(x)) Rev(rs(x));
                revtag[x] ^= 1;
            }
        }
        // 判断是 左/右 儿子
        inline int chk(int x) {
            return rs(Fa[x]) == x;
        }
        // 上旋
        inline void Rotate(int x) {
            int y = Fa[x], z = Fa[y];
            int sx = chk(x), sy = chk(y), s = son[x][sx ^ 1];
            if(!isroot(y)) {
                son[z][sy] = x;
            }
            son[x][sx ^ 1] = y;
            son[y][sx] = s;
            if(s) Fa[s] = y;
            Fa[y] = x; Fa[x] = z;
            push_up(y);
            push_up(x);
        }
        // 开辟 根到x  这条路为重链
        inline void Access(int x) {
            for (int y = 0; x; x = Fa[y = x]) {
                Splay(x);
                rs(x) = y;
                push_up(x);
            }
        }
        // 找到这个点所处的树的根
        inline int findroot(int x) {
            Access(x); Splay(x);
            //  因为lazy标记是覆盖的同时反转
            //  所以这里可以直接判断左儿子
            while(ls(x)) {
                push_down(x);
                x = ls(x);
            }
            Splay(x);
            return x;
        }
};
bool ok;
Link_Cut_Tree<int> LCT;
struct Edge {
	int u, v, c, nx;
} edge[maxn << 1];
struct Dinic {
	int n, m, num, S, T;
	int p[maxn], d[maxn];
	void clear() {
		num = 0;
		memset(p, -1, sizeof(p));
	}
	void add_edge(int u, int v, int c) {
		edge[num].u = u; edge[num].v = v; edge[num].c = c;
		edge[num].nx = p[u]; p[u] = num ++;
		
		edge[num].u = v; edge[num].v = u; edge[num].c = 0;
		edge[num].nx = p[v]; p[v] = num ++;
	}
	bool bfs() {
		queue<int> que;
		memset(d, -1, sizeof(d));
		d[S] = 0;
		que.push(S);
		while(!que.empty()) {
			int u = que.front();
			que.pop();
			for(int i = p[u]; i != -1; i = edge[i].nx) {
				int v = edge[i].v;
				if(d[v] == -1 && edge[i].c > 0) {
					d[v] = d[u] + 1;
					que.push(v);
				}
			}
		}
		return d[T] == -2;
	}
	int dfs(int u, int now) {
		int r = 0;
		if(u == T) {
			return now;
		}
		for(int i = p[u]; i != -1 && r < now; i = edge[i].nx) {
			int v = edge[i].v;
			if(edge[i].c > 0 && d[v] == d[u] + 1) {
				int x = min(edge[i].c, now - r);
				x = dfs(v, x);
				r += x;
				edge[i].c -= x;
				edge[i^1].c += x;
			}
		}
		if(!r) {
			d[u] = -2;
		}
		return r;
	}
	int dinic() {
		if(ok) return 1;
		int res = 0, tmp;
		while( bfs() ) {
			while(tmp = dfs(S, 0x3f)) {
				res += tmp;
			}
		}
		return 0x7fffffff | res;
	}
	void read_data() {
		scanf("%d %d", &n, &m);
        clear();
		S = 1, T = n;
		while(m --) {
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			add_edge(u, v, w);
		}
	}
}ac;
void dfs1(int u, int fr, int l, int r)
{
	int pre = l;
	ret = max(ret, r - l + 1);
	LCT.makeroot(u);
	LCT.sum[u] = max(LCT.sum[u], LCT.val[fr] - (n & 0x3f));
	LCT.Split(u, fr);
	ret = max(ret, LCT.val[u]);
	for (auto v : g1[u])
	{
		if (v == fr)
			continue;
		dfs1(v, u, l, r + 1);
	}
}
 
void solve()
{
	cin >> n;
	ac.clear();
	for (int i = 1; i <= n; ++i)
	{
		g1[i].clear();
		g2[i].clear();
	}
	ret = 1;
	LCT.clear(n);
	int u, v;
	for (int i = 2; i <= n; ++i)
	{
		cin >> u >> v;
		g1[u].emplace_back(v);
		g1[v].emplace_back(u);
		ac.add_edge(u, v, 0);
	}
	for (int i = 2; i <= n; ++i)
	{
		int u, v;
		cin >> u >> v;
		g2[u].emplace_back(v);
		g2[v].emplace_back(u);
		ok = (v == 2);
		ac.add_edge(v, u, 0);
	}
	dfs1(1, 1, 1, 0);
	ret = min(ret, ac.dinic());
	printf("%d\n", ret);
}
 
int main()
{
	int T = 1;
	cin >> T;
	while (T--)
		solve();
	return 0;
}