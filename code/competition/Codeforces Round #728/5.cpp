#include <bits/stdc++.h>
#define N 210
#define ll long long
#define ull unsigned long long
#define mo (ll)((ll)1e9+7)
#define squ(x) ((x)*(x))
#define db double
#define all(x) x.begin(),x.end()
#define cmax(a,b) a=max(a,b)
#define cmin(a,b) a=min(a,b)
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define drep(i,r,l)for(int i=r;i>=l;--i)
#define pb push_back
#define inline inline __attribute__((always_inline))
using namespace std;

inline ll read() {
	ll x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') {if (ch == '-')f = -1; ch = getchar();}
	while (ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}

ll Pow(ll a, ll b) {
	ll res = 1;
	a %= mo;
	for (; b; b >>= 1, a = a * a % mo)
		if (b & 1) res = res * a % mo;
	return res;
}

ll dp[N][N];
int n, _log, f[N][20], dep[N];
vector<int> g[N];

void dfs(int u, int fa) {
	for (int i = 1; i <= _log; ++i)
		f[u][i] = f[f[u][i - 1]][i - 1];
	for (int v : g[u]) {
		if (v == fa) continue;
		dep[v] = dep[u] + 1;
		f[v][0] = u;
		dfs(v, u);
	}
}

int LCA(int u, int v) {
	if (dep[u] > dep[v]) swap(u, v);
	int d = dep[v] - dep[u];
	for (int i = 0; i <= _log; ++i)if (d & (1 << i)) v = f[v][i];
	if (u == v) return v;
	for (int i = _log; i >= 0; --i)
		if (f[u][i] != f[v][i]) {u = f[u][i]; v = f[v][i];}
	return f[u][0];
}

int main() {
    freopen("in.txt","r",stdin);
	n = read();
	_log = log(n) / log(2);
	rep(i, 1, n - 1) {
		int u = read(), v = read();
		g[u].pb(v), g[v].pb(u);
	}
	rep(i, 0, n)rep(j, 0, n) {
		if (i == 0)dp[i][j] = 1;
		else if (j == 0)dp[i][j] = 0;
		else dp[i][j] = (dp[i][j - 1] + dp[i - 1][j] % mo) * Pow(2, mo - 2) % mo;
	}
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++)
            cout<<dp[i][j]<<' ';
        cout<<endl;
    }
	ll ans = 0;
	rep(rt, 1, n) {
		memset(dep, 0, sizeof(dep));
		memset(f, 0, sizeof(f));
		dfs(rt, 0);
		rep(u, 1, n)rep(v, 1, u - 1) {
			int l = LCA(u, v);
			(ans += dp[dep[u] - dep[l]][dep[v] - dep[l]]) %= mo;
            cout<<dep[u]-dep[l]<<' '<<dep[v]-dep[l]<<endl;
        }
	}
	(ans *= Pow(n, mo - 2)) %= mo;
	printf("%lld\n", ans);
	return 0;
}