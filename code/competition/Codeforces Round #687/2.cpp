/*
 * @Author: Kaizyn
 * @Date: 2020-11-29 15:01:41
 * @LastEditTime: 2020-11-29 15:47:59
 */
#include <bits/stdc++.h>
 
// #define DEBUG
 
using namespace std;
 
const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e5+7;
 
int n;
int a[N], s[N];
 
inline void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= n; ++i) s[i] = s[i-1]^a[i];
  for (int t = 0; t < n; ++t) {
    for (int i = 1; i < n; ++i) {
      for (int l = 0, r; l <= t; ++l) {
        r = t-l;
        if (i-l-1 < 0 || i+r+1 > n) continue;
        if ((s[i]^s[i-l-1]) > (s[i]^s[i+r+1])) {
          cout << t << endl;
          return;
        }
      }
    }
  }
  cout << -1 << endl;
}
 
signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}
