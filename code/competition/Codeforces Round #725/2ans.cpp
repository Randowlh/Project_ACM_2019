 
#include <bits/stdc++.h>
 
using namespace std;
 
#define dbg(x...) \
    do { \
        cout << #x << " -> "; \
        err(x); \
    } while (0)
 
void err() {
    cout << endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts &... args) {
    cout << arg << ' ';
    err(args...);
}
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef __int128 i128;
const int N = 2e5 + 10;
const int inf = 0x3f3f3f3f;
 
mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
 
ll rng(ll l, ll r) {
    uniform_int_distribution<ll> uni(l, r);
    return uni(mt);
}
 
int R, B, a, b;
 
double get(double x) {
    double rr = R - a * x;
    double bb = B - b * x;
    double y = min(rr / b, bb / a);
    return x + y;
}
 
int get(int x) {
    int rr = R - a * x;
    int bb = B - b * x;
    int y = min(rr / b, bb / a);
    return x + y;
}
 
void solve(int tCase) {
    cin >> R >> B >> a >> b;
    double l = 0, r = min(R / a, B / b);
    for (int _ = 1; _ <= 100; ++_) {
        double lmid = (l + r) / 2;
        double rmid = (lmid + r) / 2;
        double lans = calc(lmid);
        double rans = calc(rmid);
        if (lans <= rans)
            l = lmid;
        else
            r = rmid;
    }
    int ans = 0;
    for (int i = max(0, (int) (l - 1)); i <= min(min(R / a, B / b), (int) (l + 1)); ++i) {
        ans = max(ans, get(i));
    }
    cout << ans << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(false);
    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        solve(t);
    }
    return 0;
}