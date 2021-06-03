#include <bits/stdc++.h>
 
using namespace std;
 
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef __int128 i128;
const int N = 2e5 + 10;
bool mp[N][70];
int f[70];
vector<int> G[70];
int cnt = 0;
 
int find(int x) {
    return f[x] == x ? x : f[x] = find(f[x]);
}
 
void merge(int x, int y) {
    int fx = find(x);
    int fy = find(y);
    if (fx == fy) return;
    f[fy] = fx;
}
 
int n, m, p;
 
bool check(int x, int y) {
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        if (mp[i][x] && mp[i][y]) cnt++;
    }
    return cnt >= (n + 1) / 2;
}
 
 
vector<int> v;
vector<int> ans;
 
void dfs(int id, vector<bool> ok) {
    cnt++;
    if (cnt >= 200) return;
    if (ans.size() == p) return;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (ok[i]) cnt++;
    }
    if (cnt < (n + 1) / 2) return;
    if (v.size() > ans.size()) ans = v;
    for (int i : G[id]) {
        vector<bool> nxt;
        for (int j = 0; j < n; ++j) {
            nxt.push_back(ok[j] & mp[j + 1][i]);
        }
        v.push_back(i);
        dfs(i, nxt);
        v.pop_back();
        dfs(i, ok);
    }
}
 
bool sel[70];
 
void solve(int tCase) {
    cin >> n >> m >> p;
    for (int i = 1; i <= n; ++i) {
        string s;
        cin >> s;
        for (int j = 1; j <= m; ++j) {
            mp[i][j] = (s[j - 1] == '1');
        }
    }
    for (int i = 1; i <= m; ++i) {
        for (int j = i + 1; j <= m; ++j) {
            if (check(i, j)) G[i].push_back(j);
        }
    }
    for (int i = 1; i <= m; ++i) {
        vector<bool> ok;
        v.push_back(i);
        for (int j = 1; j <= n; ++j) {
            ok.push_back(mp[j][i]);
        }
        dfs(i, ok);
        v.pop_back();
    }
    for (int i : ans) sel[i] = true;
    string s;
    for (int i = 1; i <= m; ++i) {
        if (sel[i]) s += '1';
        else s += '0';
    }
    cout << s;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    int T = 1;
//    cin >> T;
    for (int t = 1; t <= T; ++t) {
        solve(t);
    }
    return 0;
}