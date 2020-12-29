#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;

typedef long long li;

int m;
li L;
int a[200];
map<li, int> sub[2][2];

int fun(li x) {
  int ans = 0;
  while (x) {
    ans ^= (x & 1);
    x >>= 1;
  }
  return ans;
}

li SolveSub(int f0, int f1, li lim) {
  li sum = 0;
  for (int len1 = 0; len1 <= 60; ++len1) {
    // 011...11
    li tail = (1LL << len1) - 1;
    if (tail > lim) break;
    li lim2 = (lim - tail) >> (len1 + 1);
    if (!(f0 == f1 && (len1 & 1) || f0 != f1 && (~len1 & 1))) continue;
    int dig = f0 ^ (len1 & 1);
    if (lim2 & 1) {
      sum += (lim2 + 1) >> 1;
    } else {
      sum += (lim2 >> 1);
      sum += (fun(lim2) == dig);
    }
  }
  return sum;
}

void Solve(void) {
  for (int i = 0; i <= 1; ++i)
    for (int j = 0; j <= 1; ++j)
      sub[i][j].clear();
  scanf("%d%lld", &m, &L);
  for (int i = 0; i < m; ++i) {
    scanf("%d", a + i);
  }

  for (int s = 0; s < 1 << 8; ++s) {
    // turn to subtask
    int x = s, c = 0;
    int f[2] = {-1, -1};
    bool bad = false;
    for (int i = 0; i < m; ++i) {
      int f_r = fun(x);
      int f_l = a[i] ^ f_r;
      if (f[c] == -1) {
        f[c] = f_l;
      }
      if (f[c] != f_l) {
        bad = true;
        break;
      }
      // shift
      ++x;
      if (x == (1 << 8)) {
        x = 0;
        c = 1;
      }
    }
    if (bad) continue;
    if (L - s < 0) continue;

    li lim = (L - s) >> 8;
    if (f[1] == -1) {
      ++sub[f[0]][0][lim];
      ++sub[f[0]][1][lim];
    } else {
      ++sub[f[0]][f[1]][lim];
    }
  }

  li ans = 0;
  for (int f0 = 0; f0 <= 1; ++f0) {
    for (int f1 = 0; f1 <= 1; ++f1) {
      for (auto p : sub[f0][f1]) {
        ans += SolveSub(f0, f1, p.first) * p.second;
      }
    }
  }
  printf("%lld\n", ans);
}

int main(void) {
  int T;
  scanf("%d", &T);
  while (T--) {
    Solve();
  }
}
